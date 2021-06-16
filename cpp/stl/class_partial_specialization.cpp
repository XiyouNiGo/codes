#include <bits/stdc++.h>

using namespace std;

template <class T, class U>
struct test_class {
  test_class() { cout << "T, U" << endl; }
};

template <class T>
struct test_class<T *, T *> {
  test_class() { cout << "T*, T*" << endl; }
};

template <class T>
struct test_class<const T *, T *> {
  test_class() { cout << "const T*, T*" << endl; }
};

int main(int argc, char *argv[]) {
  test_class<int, char>();
  test_class<int*, int*>();
  test_class<const int*, int*>();
  return 0;
}
