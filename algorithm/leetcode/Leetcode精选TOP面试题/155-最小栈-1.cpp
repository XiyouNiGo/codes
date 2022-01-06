#include <bits/stdc++.h>

#include <climits>

using namespace std;

class MinStack {
  stack<int> s;
  stack<int> min_s;

 public:
  // 解法一： 辅助栈
  MinStack() { min_s.push(INT_MAX); }

  void push(int val) {
    s.push(val);
    min_s.push(min(val, getMin()));
  }

  void pop() {
    s.pop();
    min_s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min_s.top(); }
};

int main(int argc, char *argv[]) { return 0; }