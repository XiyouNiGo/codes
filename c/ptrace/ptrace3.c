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
    ptrace(PTRACE_SYSCALL, child, NULL, NULL);

    // enter loop
    while(1){
      wait(&status);
      if(WIFEXITED(status)) break;

      // 系统调用号
      orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);

      // ** PART 1 **
      if (orig_rax != SYS_write) {
        ptrace(PTRACE_SYSCALL, child, NULL, NULL);
        continue;
      }
      // ** PART 1 END **

      printf("Got signal %d\n", WSTOPSIG(status));

      // ** PART 2 **
      /* Syscall entry */
      if(insyscall == 0) {
        insyscall = 1;
        // Linux为64位机器提供了6个保存参数的寄存器，按照顺序他们分别是：RDI、RSI、RDX、RCX、R8和R9。
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
      // ** PART 2 END **

      ptrace(PTRACE_SYSCALL, child, NULL, NULL);
    }
  }

  return 0;
}