#include "philosopher.h"

void *Philosopher(void *arg) {
  int who = (int)(long)arg;

  printf("Philosopher%d is thinking.\n", who);
  sleep(rand() % THINKING_TIME_MAX + 1);

  sem_wait(&chopsticks[who]);
  printf("Philosopher%d picked up his left-handed chopsticks.\n", who);

  sem_wait(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d picked up his right-handed chopsticks.\n", who);

  printf("Philosopher%d is eating.\n", who);
  sleep(rand() % EATING_TIME_MAX + 1);

  sem_post(&chopsticks[who]);
  printf("Philosopher%d put down his left-handed chopsticks.\n", who);

  sem_post(&chopsticks[(who + 1) % CHOPSTICKS_NUM]);
  printf("Philosopher%d put down his right-handed chopsticks.\n", who);

  return NULL;
}
