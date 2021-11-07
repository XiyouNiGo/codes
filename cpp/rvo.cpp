#include <bits/stdc++.h>

#include <type_traits>

using namespace std;

// Test RVO (Return Value Optimization)
class TestRvo {
 public:
  TestRvo() { cout << "constructor" << endl; }
  ~TestRvo() { cout << "deconstructor" << endl; }
  TestRvo(const TestRvo &other) { cout << "copy constructor" << endl; }
  // TestRvo &operator=(TestRvo tr) {
  //   // Copy And Swap
  //   cout << "operator=" << endl;
  //   // std::swap is Okay
  //   swap(*this, tr);
  //   return *this;
  // }
  TestRvo &operator=(const TestRvo &tr) {
    cout << "operator=" << endl;
    if (this == &tr) {
      // Do copy things
    }
    return *this;
  }
};

TestRvo GetTestRvo() {
  TestRvo tr;
  return tr;
}

// use -fno-elide-constructors option to forbid RVO
int main(int argc, char *argv[]) {
  TestRvo tr = GetTestRvo();
  return 0;
}
