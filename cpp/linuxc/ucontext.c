#include <stdlib.h>
#include <ucontext.h>
#include <stdio.h>
#include <string.h>

#define CO_DEFAULT_STACK_SIZE 2 * 1024 * 1024

ucontext_t ctx_task;
ucontext_t ctx_main;

void task()
{
  printf("hello ucontext\n");
  for (int i = 0; i < 10; i++) {
    swapcontext(&ctx_task, &ctx_main);
    printf("ctx_task\n");
  }
}
//合作式多任务处理
int main()
{
  int i;
  char *co_stack;

  co_stack = (char *)malloc(CO_DEFAULT_STACK_SIZE);
  if (co_stack == NULL)
  {
    return -1;
  }
  memset(co_stack, 0, CO_DEFAULT_STACK_SIZE);

  getcontext(&ctx_task);

  ctx_task.uc_stack.ss_sp = co_stack;
  ctx_task.uc_stack.ss_size = CO_DEFAULT_STACK_SIZE;
  ctx_task.uc_link = &ctx_main;
  // 上下文属于纤程，不会保存到内核的TCB
  //  节省上下文切换、调度器选择
  makecontext(&ctx_task, &task, 0);

  for (i = 0; i < 10; i++)
  {
    swapcontext(&ctx_main, &ctx_task);
    printf("main_ctx\n");
    // makecontext(&ctx_task, &task, 0);
  }

  free(co_stack);
  return 0;
}