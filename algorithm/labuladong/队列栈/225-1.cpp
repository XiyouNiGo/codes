#include <bits/stdc++.h>

#include <queue>

using namespace std;

class MyStack {
  queue<int> q1, q2;

 public:
  MyStack() {}

  void push(int x) {
    if (q1.empty()) {
      q1.push(x);
    } else {
      q2.push(x);
      while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }
      q1.swap(q2);
    }
  }

  int pop() {
    int res = q1.front();
    q1.pop();
    return res;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};

int main(int argc, char *argv[]) { return 0; }