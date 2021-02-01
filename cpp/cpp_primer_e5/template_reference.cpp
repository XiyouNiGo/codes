#include <bits/stdc++.h>

using namespace std;

template <typename T> void f1(T&);
template <typename T> void f2(const T&);
template <typename T> void f3(T&&);

int main(int argc, char *argv[]) {
  int i = 0;
  const int ci = i;

  f1(i);	//T:int
  f1(ci);	//T:const int
  f1(5);	//wrong

  f2(i);	//T:int
  f2(ci);	//T:int
  f2(5);	//T:int

  f3(i);	//T:int& 将左值传递给右值引用时，模板类型参数被推导为左值类型
  f3(ci);	//T:int
  f3(5);	//T:int

  return 0;
}
