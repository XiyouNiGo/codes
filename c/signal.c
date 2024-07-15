#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void sys_err(char *str){
	perror(str);
	exit(1);
}

void sig_handler(int num){
    printf("nigo\n");
	int status;
	pid_t pid;
	/* 由于该信号不能叠加，所以可能同时有多个子进程已经结束 所以循环wait */
	while((pid = waitpid(0, &status, WNOHANG)) > 0){
		if (WIFEXITED(status))    // 判断子进程的退出状态 是否是正常退出
			printf("-----child %d exit with %d\n", pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))   // 判断子进程是否是 通过信号退出
			printf("child %d killed by the %dth signal\n", pid, WTERMSIG(status));
	}
}

int main(void)
{
	pid_t pid;
	int i;
	/* 首先我们先将SIGCHLD信号阻塞 保证在子进程结束前设置父进程的捕捉函数 */
	sigset_t nmask, omask;
	sigemptyset(&nmask);
	sigaddset(&nmask, SIGCHLD);
	sigprocmask(SIG_BLOCK, &nmask, &omask);

	for(i=0;i<10;i++){
		pid = fork();
		if(pid == 0) break;
		if(pid == -1) sys_err("fork");
	}
	/* 子进程中循环10s */
	if(pid == 0){
		for(int i=0;i<10;i++){
			printf("This is son pid %d\n", getpid());
			sleep(1);
		}
		return i + 1;
	}
	else if(pid > 0){
		/* 父进程首先要设置好捕捉函数 */
		struct sigaction sig;
		sig.sa_handler = sig_handler;
		sigemptyset(&sig.sa_mask);
		sig.sa_flags = 0;
		sigaction(SIGCHLD, &sig, NULL);
		/* 然后再unblock */
		sigdelset(&omask, SIGCHLD);
		sigprocmask(SIG_SETMASK, &omask, NULL);
		
		while(1){
			printf("Parent pid %d\n", getpid());
			sleep(1);
		}
	}
	return 0;
}
