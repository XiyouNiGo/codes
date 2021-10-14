/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 20:57:49
 * @LastEditTime: 2021-10-14 21:26:07
 * @Description: file content
 * @FilePath: /os-cource/philosopher/philosopher-3.c
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PHILOSOPHER_NUM 5
#define CHOPSTICKS_NUM 5

#define THINKING_TIME_MAX 5
#define EATING_TIME_MAX 5
#define WAIT_TIME_MAX 5

sem_t chopsticks[CHOPSTICKS_NUM];

void *Philosopher(void *arg) {
  int who = (int)(long)arg;

  printf("Philosopher%d is thinking.\n", who);
  sleep(rand() % THINKING_TIME_MAX + 1);

  while (sem_trywait(&chopsticks[who]) != 0) {
    sleep((rand() + 1) % WAIT_TIME_MAX);
  }
  printf("Philosopher%d picked up his left-handed chopsticks.\n", who);

  while (sem_trywait(&chopsticks[(who + 1) % CHOPSTICKS_NUM]) != 0) {
    sleep((rand() + 1) % WAIT_TIME_MAX);
  }
  printf("Philosopher%d picked up his right-handed chopsticks.\n", who);

  printf("Philosopher%d is eating.\n", who);
  sleep(rand() % EATING_TIME_MAX + 1);

  sem_post(&chopsticks[who]);
  printf("Philosopher%d put down his left-handed chopsticks.\n", who);

  sem_post(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d put down his right-handed chopsticks.\n", who);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[PHILOSOPHER_NUM] = {0};

  for (int i = 0; i < CHOPSTICKS_NUM; i++) {
    sem_init(&chopsticks[i], 0, 1);
  }

  for (int i = 0; i < PHILOSOPHER_NUM; i++) {
    pthread_create(&threads[i], NULL, Philosopher, (void *)(long)i);
  }

  for (int i = 0; i < PHILOSOPHER_NUM; i++) {
    pthread_join(threads[i], NULL);
    sem_destroy(&chopsticks[i]);
  }

  return 0;
}