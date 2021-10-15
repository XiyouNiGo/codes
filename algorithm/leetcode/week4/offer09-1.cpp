#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
  CQueue() {}

  void appendTail(int value) {
    a.push(value);
  }

  int deleteHead() {
    int temp;
    if (b.size() == 0) {
      if (a.size() == 0)
        return -1;
      while (a.size()) {
        temp = a.top();
        a.pop();
        b.push(temp);
      }
    }
    temp = b.top();
    b.pop();
    return temp;
  }
private:
  stack<int> a, b;
};

int main(int argc, char* argv[])
{
  return 0;
}
