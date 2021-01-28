#include <bits/stdc++.h>

using namespace std;

template <typename T>
class A {
  inline void func() {
    static_cast<int>(A<T>());
  }
};

//template class A<int>;    //实例化定义

int main(int argc, char *argv[]) {
  A<int> a_int;
//  a_int.func();
  return 0;
}

//实例化定义会实例化所有成员和内联函数
//不实例化成员函数
//成员函数到使用时实例化
//因此注释12 16，编译通过
//注释12或者16的一个，编译错误
