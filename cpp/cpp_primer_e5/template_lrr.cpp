#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f(T&&) {
  cout << "I'm void f(T&&)" << endl;
}

template <typename T>
void f(const T&) {
  cout << "I'm void f(const T&)" << endl;
}

int main(int argc, char *argv[]) {
  int i = 0;
  const int ci = i;
  int &rr = i;
  int &&lr = 0;
  const int &&clr = 0;
  f(0);
  f(i);
  f(ci);
  f(rr);
  f(lr);
  f(clr);
  return 0;
}
