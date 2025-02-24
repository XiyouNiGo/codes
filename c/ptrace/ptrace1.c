#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/reg.h>

int main(void){
    pid_t child;
    long orig_rax;
    child = fork();
    if (child == 0){
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        // 如果execl系统调用的进程处于PTRACE_TRACEME状态的话，就会发送一个SIGTRAP信号给父进程，并让自身处于Traced状态
        // 它的含义是停止执行程序，以便进行调试操作
        execl("/bin/ls", "ls", "-l", "-h", NULL);
    } else {
        // 接收子进程调用execl时产生的SIGTRAP信号
        wait(NULL);
        // 读取tracee进程的USER字段中相关偏移量位置的值(struct user_regs_struct)
        // 寄存器信息和其他信息
        orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
        printf("Child process called a system call, id is %ld\n", orig_rax);
        // 恢复处于Traced状态的tracee进程。最后一个参数表示发送给tracee进程的信号。
        ptrace(PTRACE_CONT, child, NULL, NULL);
    }

    return 0;
}
