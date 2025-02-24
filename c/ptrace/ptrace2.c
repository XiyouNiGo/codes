#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv){
  pid_t child = fork();
  int status = 0;
  long orig_rax = 0;
  if (child == 0){
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execl("/bin/ls", "ls", "-l", "-h", NULL);
  } else {
    while(1){
      wait(&status);
      printf("Got signal %d\n", WSTOPSIG(status));
      if(WIFEXITED(status)) break;

      orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
      printf("Program called system call: %ld\n", orig_rax);
      // 发生system call相关的事件时子进程需要通知父进程（调用和结束都触发一次）
      ptrace(PTRACE_SYSCALL, child, NULL, NULL);
    }
  }
  return 0;
}