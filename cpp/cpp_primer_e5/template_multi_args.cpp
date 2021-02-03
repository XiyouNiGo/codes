#include <bits/stdc++.h>

using namespace std;

//非模板版本终止递归
template <typename T>
ostream &print(ostream &os, const T &t) {
  return os << t;
}

template<typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ... rest) {
  os << t << ",";
  return print(os, rest...);
}

int main(int argc, char *argv[]) {
  print(cout, "我", "咋这么", "菜呢");
  return 0;
}
