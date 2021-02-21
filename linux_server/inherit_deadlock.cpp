#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

pthread_mutex_t mutex;

void *another(void *arg) {
  printf("in child thread, lock the mutex\n");
  pthread_mutex_lock(&mutex);
  sleep(5);
  pthread_mutex_unlock(&mutex);
}

void prepare() {
  pthread_mutex_lock(&mutex);
}

void infork() {
  pthread_mutex_unlock(&mutex);
}

//子进程只拥有一个执行线程
//它是调用fork的线程的完整复制
//互斥锁的状态将被自动继承
//父进程的其他线程可能加锁
//此时子进程加锁就会导致死锁
int main() {
  pthread_mutex_init(&mutex, NULL);
  pthread_t id;
  pthread_create(&id, NULL, another, NULL);
  //pthread_atfork( prepare, infork, infork );
  sleep(1);
  int pid = fork();
  if (pid < 0) {
	pthread_join(id, NULL);
	pthread_mutex_destroy(&mutex);
	return 1;
  } else if (pid == 0) {
	printf("I am in the child, want to get the lock\n");
	pthread_mutex_lock(&mutex);
	printf("I can not run to here, oop...\n");
	pthread_mutex_unlock(&mutex);
	exit(0);
  } else {
	pthread_mutex_unlock(&mutex);
	wait(NULL);
  }
  pthread_join(id, NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}

