#include <iostream>
#include <string>
#include "my_string.h"
#include "my_iterator.h"

using namespace std;

int main() {
  string s("abcd");
  const char *p = s.c_str();
  reverse_random_access_iterator<char> q(p+3, s.size(), 0);
  cout << *q << endl;
  cout << *(q+2) << endl;
  cout << *++q << endl;
  return 0;
}
