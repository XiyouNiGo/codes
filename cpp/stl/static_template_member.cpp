#include <bits/stdc++.h>

using namespace std;

template <typename T>
class test_class {
 public:
  static int data;
};

// initialize
template<> int test_class<int>::data = 1;
template<> int test_class<char>::data = 2;

int main(int argc, char *argv[])
{
  cout << test_class<int>::data << endl;
  cout << test_class<char>::data << endl;
  return 0;
}
