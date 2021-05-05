#include <stdio.h>
#include <pthread.h>

// 借助互斥锁和条件变量实现信号量

typedef struct my_sem {
    int value;  // 绝对资源
    int wakeup; // 临时资源，防止伪唤醒
    pthread_mutex_t lock;
    pthread_cond_t cond;
} my_sem;

void my_sem_init(my_sem *s, unsigned int value)
{
    s->value = value;
    s->wakeup = 0;
    pthread_mutex_init(&(s->lock), NULL);
    pthread_cond_init(&(s->cond), NULL);
}

void my_sem_destory(my_sem *s)
{
    pthread_mutex_destroy(&(s->lock));
    pthread_cond_destroy(&(s->cond));
}

void my_sem_wait(my_sem *s)
{
    pthread_mutex_lock(&(s->lock));
    s->value--;
    if (s->value < 0) {
        // do-while而不是while：有限等待（先到先得）
        do {
            pthread_cond_wait(&(s->cond), &(s->lock));
        } while (s->wakeup == 0);
        s->wakeup--;
    }
    pthread_mutex_unlock(&(s->lock));
}

void my_sem_post(my_sem *s)
{
    pthread_mutex_lock(&(s->lock));
    s->value++;
    // 注意这个=号
    if (s->value <= 0) {
        s->wakeup++;
        pthread_cond_signal(&(s->cond));
    }
    pthread_mutex_unlock(&(s->lock));
}

int main()
{
    printf("Hello world\n");
    return 0;
}

