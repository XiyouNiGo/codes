#include <iostream>
#include <thread>

int main() {
  unsigned int in = std::thread::hardware_concurrency();
  std::cout << in << std::endl;
}