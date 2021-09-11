#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid;
  printf("Before fork ...\n");
  switch (pid = fork()) {
    case -1:
      printf("fork call fail\n");
      // unnecessary
      fflush(stdout);
      break;
    case 0:
      printf("I am child.\n");
      printf("The pid of child is: %d\n", getppid());
      printf("The pid of child's parent is: %d\n", getppid());
      printf("Child exiting...\n");
    default:
      printf("I am father.\n");
      printf("The pid of parent is: %d.\n", getpid());
      printf("The pid of parent's child is: %d.\n", pid);
      break;
  }
  printf("After fork, program exiting...\n");
  exit(0);
}