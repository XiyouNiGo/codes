#include <bits/stdc++.h>

using namespace std;

//重载模板
template <typename T>
string debug_rep(const T &t) {
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
string debug_rep(T *p) {
  ostringstream ret;
  ret << "pointer : " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " nullptr";
  return ret.str();
}

int main(int argc, char *argv[]) {
  string s("test");
  const string cs("cs");

  cout << debug_rep(s) << endl;
  cout << debug_rep(&s) << endl;

  //当有多个重载模板对一个调用提供同样好的匹配时
  //应选择最特例化的版本

  cout << debug_rep(&cs) << endl;

  return 0;
}
