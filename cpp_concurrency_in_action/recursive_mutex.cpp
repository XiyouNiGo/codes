#include <iostream>
#include <mutex>
#include <thread>

class X {
  std::recursive_mutex m;
  std::string shared;

 public:
  void fun1() {
    std::lock_guard<std::recursive_mutex> lk(m);
    shared = "fun1";
    std::cout << "in fun1, shared variable is now " << shared << '\n';
  }
  void fun2() {
    std::lock_guard<std::recursive_mutex> lk(m);
    shared = "fun2";
    std::cout << "in fun2, shared variable is now " << shared << '\n';
    /* recursive lock */
    fun1();
    std::cout << "back in fun2, shared variable is " << shared << '\n';
  };
};

int main() {
  X x;
  std::thread t1(&X::fun1, &x);
  std::thread t2(&X::fun2, &x);
  t1.join();
  t2.join();
}