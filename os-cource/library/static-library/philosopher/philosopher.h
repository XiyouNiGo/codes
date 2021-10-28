#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PHILOSOPHER_NUM 5
#define CHOPSTICKS_NUM 5

#define THINKING_TIME_MAX 5
#define EATING_TIME_MAX 5

sem_t chopsticks[CHOPSTICKS_NUM];

void *Philosopher(void *arg);

#endif // PHILOSOPHER_H_