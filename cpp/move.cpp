#include <bits/stdc++.h>

using namespace std;

template <typename T>
typename remove_reference<T>::type &&my_move(T &&t) {
  return static_cast<typename remove_reference<T>::type &&>(t);
}

int main(int argc, char *argv[]) {
  string s1("hi!"), s2;
  s2 = my_move(string("bye!"));
  s2 = my_move(s1);
  return 0;
}
