#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/syscall.h>

int main(int argc, char **argv){
  pid_t child = fork();
  int status = 0;
  long orig_rax = 0;
  long rax = 0;
  int insyscall = 0;
  long params[3];
  if (child == 0){
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execl("/bin/ls", "ls", "-l", "-h", NULL);
  } else {
    // ignore the first SIGTRAP signal
    wait(&status);
    // 通过PTRACE_SETOPTIONS操作传递PTRACE_O_TRACESYSGOOD给tracee进程，从而让tracee进程发送给tracer进程的信号编号（signal code）由5) SIGTRAP变成5 | 0x80
    ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
    ptrace(PTRACE_SYSCALL, child, NULL, NULL);

    // enter loop
    while(1){
      wait(&status);
      if(WIFEXITED(status)) break;

      if (! (WSTOPSIG(status) & 0x80)) {
        ptrace(PTRACE_SYSCALL, child, NULL, NULL);
        continue;
      }

      orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);

      if (orig_rax != SYS_write) {
        ptrace(PTRACE_SYSCALL, child, NULL, NULL);
        continue;
      }

      printf("Got signal %d\n", WSTOPSIG(status));

      /* Syscall entry */
      if(insyscall == 0) {
        insyscall = 1;
        params[0] = ptrace(PTRACE_PEEKUSER, child, 8 * RDI, NULL);
        params[1] = ptrace(PTRACE_PEEKUSER, child, 8 * RSI, NULL);
        params[2] = ptrace(PTRACE_PEEKUSER, child, 8 * RDX, NULL);
        printf("Write called with %ld, %ld, %ld\n", params[0], params[1], params[2]);
      } else {
      /* Syscall exit */
        rax = ptrace(PTRACE_PEEKUSER, child, 8 * RAX, NULL);
        printf("Write returned with %ld\n", rax);
        insyscall = 0;
      }

      ptrace(PTRACE_SYSCALL, child, NULL, NULL);
    }
  }

  return 0;
}