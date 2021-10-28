#include "philosopher.h"

#include <stdio.h>

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
