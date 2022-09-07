#include <bits/stdc++.h>

using namespace std;

class MyQueue {
 public:
  stack<int> stIn;
  stack<int> stOut;

  MyQueue() {}

  void push(int x) { stIn.push(x); }

  int pop() {
    if (stOut.empty()) {
      while (!stIn.empty()) {
        stOut.push(stIn.top());
        stIn.pop();
      }
    }
    int result = stOut.top();
    stOut.pop();
    return result;
  }

  int peek() {
    int res = this->pop();
    stOut.push(res);
    return res;
  }

  bool empty() { return stIn.empty() && stOut.empty(); }
};

int main(int argc, char *argv[]) { return 0; }