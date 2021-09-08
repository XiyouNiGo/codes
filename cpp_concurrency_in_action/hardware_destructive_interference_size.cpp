#include <iostream>
#include <new>
#include <thread>

int main() {
  /* the size of cache line*/
  std::cout << std::hardware_destructive_interference_size() << std::endl;
}