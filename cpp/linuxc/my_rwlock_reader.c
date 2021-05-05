#include <stdio.h>
#include <pthread.h>

// 偏向读者的读写锁
// 区别：新的写者到达到达后是否阻塞后续读者

typedef struct my_rwlock_reader {
    int reader_cnt;
    pthread_mutex_t reader_lock;
    pthread_mutex_t writer_lock;
} my_rwlock_reader;

void lock_reader(my_rwlock_reader *lock)
{
    pthread_mutex_lock(&lock->reader_lock);
    ++lock->reader_cnt;
    if (lock->reader_cnt == 1) {
        pthread_mutex_lock(&lock->writer_lock);
    }
    pthread_mutex_unlock(&lock->reader_lock);
}

void unlock_reader(my_rwlock_reader *lock)
{
    pthread_mutex_lock(&lock->reader_lock);
    --lock->reader_cnt;
    if (lock->reader_cnt == 0) {
        pthread_mutex_unlock(&lock->writer_lock);
    }
    pthread_mutex_unlock(&lock->reader_lock);
}

void lock_writer(my_rwlock_reader *lock)
{
    pthread_mutex_lock(&lock->writer_lock);
}

void unlock_writer(my_rwlock_reader *lock)
{
    pthread_mutex_unlock(&lock->writer_lock);
}

int main()
{
    printf("Hello world\n");
    return 0;
}

