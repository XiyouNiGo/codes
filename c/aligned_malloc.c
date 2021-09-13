#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// alignment shouble be the power of 2.
void* aligned_malloc(size_t required_bytes, size_t alignment) {
  // mask之前的空间刚好为sizeof(void*) - 1的情况为需要补齐字节数最多的情况
  // 我们可以多申请，但是不能少申请
  int offset = alignment - 1 + sizeof(void*);
  printf("offset: %d\n", offset);
  void* p1 = (void*)malloc(required_bytes + offset);
  printf("p1: %p\n", p1);
  if (p1 == NULL) return NULL;
  // Work like umask.
  void** p2 = (void**)(((size_t)p1 + offset) & ~(alignment - 1));
  printf("p2: %p\n", p2);
  p2[-1] = p1;
  // Implicit conversion.
  return p2;
}

void aligned_free(void* p2) {
  void* p1 = ((void**)p2)[-1];
  free(p1);
}

int main(int argc, char *argv[]) {
  char *ap = aligned_malloc(100, 16);
  aligned_free(ap);
  return 0;
}