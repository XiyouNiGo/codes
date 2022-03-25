#include <bits/stdc++.h>

#include <stack>

using namespace std;

class MyQueue {
  stack<int> s1, s2;

 public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int res = s2.top();
    s2.pop();
    return res;
  }

  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }
};

int main(int argc, char *argv[]) { return 0; }