#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

class Base {
};

class Derive : public Base {
};

//获得有关编译时的类型信息
int main(int argc, char *argv[]) {
  char arr[10];

  cout << is_array<decltype(arr)>::value << endl;
  cout << is_array<vector<int>>::value << endl;
  cout << is_array<array<int, 5>>::value << endl;

  cout << is_const<int>::value << endl;
  cout << is_const<const int>::value << endl;

  cout << is_function<decltype(main)>::value << endl;
  cout << is_function<decltype(main)*>::value << endl;

  cout << is_base_of<Base, Derive>::value << endl;
  cout << is_base_of<Derive, Base>::value << endl;

  cout << is_same<int, int>::value << endl;
  cout << is_same<int, double>::value << endl;

  return 0;
}
