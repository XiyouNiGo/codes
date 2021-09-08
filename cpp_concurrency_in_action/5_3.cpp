#include <iostream>

void foo(int a, int b) { std::cout << a << "," << b << std::endl; }

int get_num() {
  static int i = 0;
  return ++i;
}
/* result is "2,1", this confirms that function convey parameters from right to
 * left */
int main() { foo(get_num(), get_num()); }
