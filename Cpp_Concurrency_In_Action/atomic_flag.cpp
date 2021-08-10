#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_flag lock = ATOMIC_FLAG_INIT;

int global_int = 0;

void f() {
  /* use atomic_flag to implement spinlock mutex */
  for (int cnt = 0; cnt < 20; ++cnt) {
    while (lock.test_and_set(std::memory_order_acquire));
    /* now we get lock */
    std::cout << global_int++ << " ";
    lock.clear();
  }
}

int main() {
  std::vector<std::thread> v;
  for (int n = 0; n < 10; ++n) {
    v.emplace_back(f);
  }
  for (auto& t : v) {
    t.join();
  }
}