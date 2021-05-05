#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// 偏向写着的读写锁

typedef struct my_rwlock_writer {
    volatile int reader_cnt;
    volatile bool has_writer;
    pthread_mutex_t lock;
    pthread_cond_t reader_cond;
    pthread_cond_t writer_cond;
} my_rwlock_writer;

void lock_reader(my_rwlock_writer *lock)
{
    pthread_mutex_lock(&lock->lock);
    // 防止伪唤醒
    while (lock->has_writer == true) {
        pthread_cond_wait(&lock->writer_cond, &lock->lock);
    }
    ++lock->reader_cnt;
    pthread_mutex_unlock(&lock->lock);
}

void unlock_reader(my_rwlock_writer *lock)
{
    pthread_mutex_lock(&lock->lock);
    --lock->reader_cnt;
    if (lock->reader_cnt == 0) {
        // reader:signal
        pthread_cond_signal(&lock->reader_cond);
    }
    pthread_mutex_unlock(&lock->lock);
}

void lock_writer(my_rwlock_writer *lock)
{
    pthread_mutex_lock(&lock->lock);
    while (lock->has_writer == true) {
        pthread_cond_wait(&lock->writer_cond, &lock->lock);
    }
    lock->has_writer = true;
    while (lock->reader_cnt > 0) {
        pthread_cond_wait(&lock->reader_cond, &lock->lock);
    }
    pthread_mutex_unlock(&lock->lock);
}

void unlock_writer(my_rwlock_writer *lock)
{
    pthread_mutex_lock(&lock->lock);
    lock->has_writer = false;
    // writer:broadcast
    pthread_cond_broadcast(&lock->writer_cond);
    pthread_mutex_unlock(&lock->lock);
}

int main()
{
    printf("Hello world\n");
    return 0;
}

