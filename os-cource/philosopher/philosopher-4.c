/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 20:58:31
 * @LastEditTime: 2021-10-14 21:23:48
 * @Description: file content
 * @FilePath: /os-cource/philosopher/philosopher-4.c
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

sem_t pickup_left;
sem_t chopsticks[CHOPSTICKS_NUM];

void *Philosopher(void *arg) {
  int who = (int)(long)arg;

  printf("Philosopher%d is thinking.\n", who);
  sleep(rand() % THINKING_TIME_MAX + 1);

  sem_wait(&pickup_left);
  sem_wait(&chopsticks[who]);
  printf("Philosopher%d picked up his left-handed chopsticks.\n", who);

  sem_wait(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d picked up his right-handed chopsticks.\n", who);

  printf("Philosopher%d is eating.\n", who);
  sleep(rand() % EATING_TIME_MAX + 1);

  sem_post(&chopsticks[who]);
  sem_post(&pickup_left);
  printf("Philosopher%d put down his left-handed chopsticks.\n", who);

  sem_post(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d put down his right-handed chopsticks.\n", who);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[PHILOSOPHER_NUM] = {0};

  sem_init(&pickup_left, 0, PHILOSOPHER_NUM - 1);
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