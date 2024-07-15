#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
static int self;
static char *self_id = "ABCD";
#define pr_info(fmt, ...) \
        printf("[%ld] ID %c: " fmt "\n", time(NULL), self_id[self], ##__VA_ARGS__)
#define show_info() \
        pr_info("pid %d: %s", getpid(), __func__)
int do_fork(void);
void dispatch(int);
int main(int argc, char *argv[])
{
        self = do_fork();
        dispatch(self);
        return EXIT_SUCCESS;
}
/* A -> B -> C -> D */
int do_fork(void)
{
        int count = 0;
        while (1) {
                if (count < 3) {
                        switch (fork()) {
                        case -1:
                                /* error */
                                perror("fork");
                                exit(EXIT_FAILURE);
                        case 0:
                                /* this is child process, do fork again */
                                count++;
                                break;
                        default:
                                /* this is parent process, break */
                                return count;
                        }
                } else {
                        return count;
                }
        }
        /* unreachable */
        return 0;
}
void do_wait(void)
{
        int wstatus;
        pid_t pid;
        while (1) {
                /* Reference: https://man7.org/linux/man-pages/man2/waitpid.2.html */
                if ((pid = wait(&wstatus)) == -1) {
                        pr_info("No child process");
                        sleep(5);
                        break;
                }
                if (WIFEXITED(wstatus)) {
                        pr_info("pid %d is exited, status=%d", pid,
                                WEXITSTATUS(wstatus));
                } else if (WIFSIGNALED(wstatus)) {
                        pr_info("pid %d is killed by signal %d", pid,
                                WTERMSIG(wstatus));
                } else if (WIFSTOPPED(wstatus)) {
                        pr_info("pid %d is stopped by signal %d", pid,
                                WSTOPSIG(wstatus));
                } else if (WIFCONTINUED(wstatus)) {
                        pr_info("pid %d is continued", pid);
                }
        }
}
void sigchld_handler(int unused)
{
        pr_info("SIGCHLD handled");
}
void do_signal(void)
{
        struct sigaction act = { .sa_handler = sigchld_handler };
        /* Reference: https://man7.org/linux/man-pages/man2/sigaction.2.html */
        if (sigaction(SIGCHLD, &act, NULL) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }
}
/* A */
void proc_init(void)
{
        show_info();
        do_signal();
        do_wait();
}
/* B */
void proc_subreaper(void)
{
        show_info();
        do_signal();
        /* Reference: https://man7.org/linux/man-pages/man2/prctl.2.html */
        if (prctl(PR_SET_CHILD_SUBREAPER, 1, 0, 0, 0) < 0) {
                perror("prctl");
                exit(EXIT_FAILURE);
        }
        do_wait();
}
/* C */
void proc_abnormal(void)
{
        show_info();
        /* fork without wait */
        do_signal();
        pr_info("sleep for 10s");
        sleep(10);
}
/* D */
void proc_defunct(void)
{
        show_info();
        sleep(5);
        pr_info("exit");
        exit(EXIT_SUCCESS);
}
typedef void (*test_func)(void);
void dispatch(int id)
{
        test_func func[4] = { proc_init, proc_subreaper, proc_abnormal, proc_defunct};
        func[id]();
}
（已编辑）
