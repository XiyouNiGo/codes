#include <iostream>

#include "hello/say_hello.h"

void say_hello() {
  std::cout << "Hello shared library by LD_PRELOAD!" << std::endl;
}