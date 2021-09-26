#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#define gettid() syscall(__NR_gettid)

pthread_t ntid;

void *printids(void *s) {
  pid_t pid;
  pid_t ktid;  // Kernel thread id
  pthread_t utid;  // User thread id

  pid = getpid();
  ktid = gettid();
  utid = pthread_self();

  printf("%s pid %d ktid %d utid %lu (0x%lx)\n", (char*)s, pid, ktid, utid, utid);

  pause();
}

int main(int argc, char *argv[]) {
  pthread_create(&ntid, NULL, printids, "New thread:");
  printids("Main thread:");
  sleep(1);
  return 0;
}