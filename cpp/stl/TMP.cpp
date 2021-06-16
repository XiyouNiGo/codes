#include <bits/stdc++.h>

using namespace std;

template<unsigned n>
struct Factorial {
  enum { value = n * Factorial<n - 1>::value };
};

template<>
struct Factorial<0> {
  enum { value = 1 };
};

int main(int argc, char *argv[]) {
  cout << "Factorial<5>::value is "
	   << Factorial<5>::value << endl;
  return 0;
}
