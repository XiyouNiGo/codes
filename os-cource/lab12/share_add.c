#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

#define PTHREAD_NUM 16LU
#define ADD_TIMES 10000LU

unsigned long sum = 0;

void *thread(void *arg) {
    /* for (int i = 0; i < ADD_TIMES; i++) { sum += 1; } */
    for (int i = 0; i < ADD_TIMES; i++) {
        __sync_add_and_fetch(&sum, 1);
    };
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

