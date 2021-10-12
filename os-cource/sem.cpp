/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-11 22:05:59
 * @LastEditTime: 2021-10-11 22:18:59
 * @Description: file content
 * @FilePath: /os-cource/sem.cpp
 */
#include <bits/stdc++.h>

using namespace std;

struct task_struct {};
struct task_struct this_thread;

class sem {
 public:
  void wait() {
    count_--;
    if (count_ < 0) {
      queue_.push(::this_thread);
    }
  }

  void signal() {
    count_++;
    if (count_ > 0) {
      wake(queue_.front());
      queue_.pop();
    }
  }

 private:
  int count_;
  queue<struct task_struct> queue_;
  void wake(struct task_struct s) {}
};

int main(int argc, char *argv[]) { return 0; }