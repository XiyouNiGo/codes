#include <bits/stdc++.h>
#include <boost/noncopyable.hpp>
#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>

using namespace std;
using namespace muduo;

class CountDownLatch : boost::noncopyable {
 public:

  explicit CountDownLatch(int count) : mutex_(),
  condition_(mutex_), count_(count) { }

  void wait() {
    MutexLockGuard lock(mutex_);
    while (count_ > 0)
      condition_.wait();
  }

  void countDown() {
    MutexLockGuard lock(mutex_);
    --count_;
    if (count_ == 0)
      condition_.notifyAll();
  }

  int getCount() const {
    MutexLockGuard lock(mutex_);
    return count_;
  }

 private:
  //先mutex_再condition_
  mutable MutexLock mutex_;
  Condition condition_;
  int count_;
};

int main(int argc, char *argv[]) {
  return 0;
}
