#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int i = 1;
  int *p = &i;
  cout << static_cast<char>(*p) << endl;
  cout << *p << endl;
  return 0;
}
