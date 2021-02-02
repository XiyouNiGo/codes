#include <bits/stdc++.h>

using namespace std;

void f(int v1, int &v2) {
  cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int &j) {
  cout << i << " " << j << endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
  f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
  f(t2, t1);
}

//使用std::forward转发
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main(int argc, char *argv[]) {
  int v1, v2;
  v1 = v2 = 0;

  flip1(f, v1, v2);
  cout << "v1 : " << v1 << " v2 : " << v2 << endl;

  //Rvalue reference to type 'int' cannot bind to lvalue of type 'int'
//  flip2(g, v1, 42);
  flip(g, v1, 42);
  return 0;
}
