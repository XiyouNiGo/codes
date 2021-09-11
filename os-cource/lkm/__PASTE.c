#include <stdio.h>

#define __PASTE(a, b) a##b

int main(int argc, char *argv[]) {
  // result: __PASTE(a, b) c;
  __PASTE(__PASTE(a, b), c);
  return 0;
}
