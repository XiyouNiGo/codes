/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-09-28 11:22:22
 * @LastEditTime: 2021-10-08 21:15:50
 * @Description: file content
 * @FilePath: /os-cource/lab12/share_add3.c
 */
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PTHREAD_NUM 16LU
#define ADD_TIMES 100000LU

unsigned long sum = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *arg) {
  for (int i = 0; i < ADD_TIMES; i++) {
    pthread_mutex_lock(&lock);
    sum += 1;
    pthread_mutex_unlock(&lock);
  }
}

int main(int argc, char *argv[]) {
  printf("Before: sum = %lu\n", sum);

  pthread_t pthread[PTHREAD_NUM] = {0};
  int ret = 0;

  void *retval[PTHREAD_NUM];

  for (int i = 0; i < PTHREAD_NUM; i++) {
    ret = pthread_create(&pthread[i], NULL, thread, NULL);
    if (ret != 0) {
      perror("pthread_create error");
    }
  }

  for (int i = 0; i < PTHREAD_NUM; i++) {
    pthread_join(pthread[i], &retval[i]);
  }

  printf("After: sum = %lu\n", sum);
  printf("Expect: sum = %lu\n", PTHREAD_NUM * ADD_TIMES);
  return 0;
}
