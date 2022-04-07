#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int A(int n1, int n2) {
    int res = 1;
    for (int i = n2; i > n2 - n1; i--) {
      res *= i % 1000000;
      res %= 1000000;
    }
    return res;
  }
  int numsOfStrings(int n, int k) {
    int a = 0, b = 1;
    if (k == 0 || k == 1) {
      return A(k, 26);
    }
    for (int i = 2; i <= k; i++) {
      cout << a << "" << b << endl;
      int t = b;
      b += a;
      a = t;
    }
    return b;
    // return A(b, 26);
  }
};

int main(int argc, char *argv[]) {
  cout << Solution().numsOfStrings(2, 7);
  return 0;
}