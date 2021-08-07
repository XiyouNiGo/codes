#include <stdio.h>
#include <stdlib.h>

/* assumes old memory has freed */
void *my_realloc(void *ptr, size_t size) {
  void *new_memory = realloc(ptr, size);
  if (new_memory == NULL && size != 0) {
    free(ptr);
  }
  return new_memory;
}

int main(int argc, char *argv[]) { return 0; }
