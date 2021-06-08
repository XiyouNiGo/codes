#include <bits/stdc++.h>

using namespace std;

class MaxQueue {
  deque<int> q1, q2;
 public:
  MaxQueue() {}

  int max_value() {
    return q2.empty() ? -1 : q2.front();
  }

  void push_back(int value) {
    q1.push_back(value);
    while (!q2.empty() && q2.back() < value) {
      q2.pop_back();
    }
    q2.push_back(value);
  }

  int pop_front() {
    if (q1.empty()) {
      return -1;
    }
    int res = q1.front();
    q1.pop_front();
    if (res == q2.front()) {
      q2.pop_front();
    }
    return res;
  }
};

int main(int argc, char *argv[])
{
    return 0;
}
