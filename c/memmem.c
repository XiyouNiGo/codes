#include <stdio.h>
#include <string.h>

static const char *crlf = "\r\n";
void *FindCrlf(const char *buffer, int size) {
  return memmem(buffer, size, crlf, 2);
}

int main(int argc, char *argv[]) {
  char buffer1[] = "begin\r\nmid\r\nend";
  void *ret = FindCrlf(buffer1, sizeof(buffer1));
  printf("%p %p %p\n", ret, buffer1, crlf);
  printf("|%s|\n", ret ? (const char *)ret : "Not found.");
  /* return 0; */

  char buffer2[] = "begin\r\n";
  ret = FindCrlf(buffer2, sizeof(buffer2));
  printf("|%s|\n", ret ? (const char *)ret : "Not found.");
  return 0;
}

