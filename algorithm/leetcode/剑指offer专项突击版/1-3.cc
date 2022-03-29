#include <bits/stdc++.h>

#include <cstdlib>
#include <iterator>
#include <ostream>

using namespace std;

class Solution {
 public:
  // 位运算优化（错的是什么鬼）
  // O(logN)
  int divide(int a, int b) {
    if (a == INT_MIN && b == -1) {
      return INT_MAX;
    }
    int res = 0;
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;
    a = a > 0 ? -a : a;
    b = b > 0 ? -b : b;
    while (a <= b) {
      int exp = 0;
      while (a <= (b << exp)) {
        exp++;
      }
      if (exp != 0) {
        exp--;
      }
      a -= (b << exp);
      res += (1 << exp);
    }
    return sign == 1 ? res : -res;
  }
};

int main(int argc, char *argv[]) {
  cout << Solution().divide(15, 2) << endl;
  return 0;
}