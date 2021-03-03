#include <bits/stdc++.h>

using namespace std;

class A {
 public:
  virtual void f(string s = "A") {
    cout << s << endl;
  }
};

class B : public A {
 public:
  virtual void f(string s = "B") {
    cout << s << endl;
  }
};

//静态绑定下不会继承缺省参数值
//动态绑定会
int main(int argc, char *argv[]) {
  B b;
  b.f();
  A *pa = &b;
  pa->f();
  return 0;
}
