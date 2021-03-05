#include <bits/stdc++.h>
#include <boost/noncopyable.hpp>
#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>

using namespace std;

muduo::MutexLock mutex_;
muduo::Condition cond(mutex_);
std::deque<int> queue_;

int dequeue() {
  muduo::MutexLockGuard lock(mutex_);
  //用if会导致虚假唤醒
  while (queue_.empty()) {
    cond.wait();
  }
  assert(!queue_.empty());
  int top = queue_.front();
  queue_.pop_front();
  return top;
}

void enqueue(int x) {
  MutexLockGuard lock(mutex_);
  queue_.push_back(x);
  cond.notify();
}

int main(int argc, char *argv[]) {
  return 0;
}
