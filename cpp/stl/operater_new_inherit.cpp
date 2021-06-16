#include <bits/stdc++.h>

using namespace std;

class A {
 public:
  void *operator new(std::size_t size) {
	cout << "A" << endl;
  }
};

class B : public A {
 public:
//  void *operator new(std::size_t size) {
//	cout << "B" << endl;
//  }
};

int main(int argc, char *argv[]) {
  B* pb = new B;
  return 0;
}
