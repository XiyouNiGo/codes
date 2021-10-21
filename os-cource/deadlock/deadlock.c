/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-21 14:17:36
 * @LastEditTime: 2021-10-21 14:49:10
 * @Description: file content
 * @FilePath: /os-cource/deadlock/deadlock.c
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PHILOSOPHER_NUM 5
#define CHOPSTICKS_NUM 5

sem_t chopsticks[CHOPSTICKS_NUM];

pthread_barrier_t begin2pick;

void *Philosopher(void *arg) {
  int who = (int)(long)arg;

  printf("Philosopher%d is thinking.\n", who);

  pthread_barrier_wait(&begin2pick);
  sem_wait(&chopsticks[who]);
  printf("Philosopher%d picked up his left-handed chopsticks.\n", who);
  sleep(1);

  sem_wait(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d picked up his right-handed chopsticks.\n", who);

  printf("Philosopher%d is eating.\n", who);

  sem_post(&chopsticks[who]);
  printf("Philosopher%d put down his left-handed chopsticks.\n", who);

  sem_post(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d put down his right-handed chopsticks.\n", who);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[PHILOSOPHER_NUM] = {0};

  pthread_barrier_init(&begin2pick, NULL, PHILOSOPHER_NUM);
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
  pthread_barrier_destroy(&begin2pick);

  return 0;
}