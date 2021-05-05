#include <stdio.h>
#include <pthread.h>

#define true 1
#define false 0

// 皮特森算法
// 无法在发生指令重排的CPU上工作

int data, turn;
int flag[2];

void *t0(void *args)
{
    while (true) {
        flag[0] = true;
        // 设为对方而不是自己
        turn = 1;

        while (flag[1] == true && turn == 1);
        // 访问临界区
        data++;

        flag[0] = true;

        printf("t0: data is %d\n", data);
    }
}

void *t1(void *args)
{
    while (true) {
        flag[1] = true;
        turn = 0;

        while (flag[0] == true && turn == 0);
        // 访问临界区
        data++;

        flag[1] = true;

        printf("t1: data is %d\n", data);
    }
}

int main()
{
    data = 0;
    flag[0] = flag[1] = false;

    pthread_t tids[2];
    pthread_create(&tids[0], NULL, t0, NULL);
    pthread_create(&tids[1], NULL, t1, NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(tids[i], NULL);

    return 0;
}

