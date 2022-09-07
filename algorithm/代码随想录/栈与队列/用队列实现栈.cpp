#include <bits/stdc++.h>

using namespace std;

class MyStack {
 public:
  // 双队列：一个队列也行
  queue<int> que1;
  queue<int> que2;
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { que1.push(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int size = que1.size();
    size--;
    while (size--) {
      que2.push(que1.front());
      que1.pop();
    }

    int result = que1.front();
    que1.pop();
    que1 = que2;
    while (!que2.empty()) {
      que2.pop();
    }
    return result;
  }

  /** Get the top element. */
  int top() { return que1.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return que1.empty(); }
};

int main(int argc, char *argv[]) { return 0; }