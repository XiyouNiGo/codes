#include <bits/stdc++.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  // 用减法模拟（考虑INT_MIN绝对值还是INT_MIN）
  // O(N)超时
  int divide(int a, int b) {
    if (a == INT_MIN && b == -1) {
      return INT_MAX;
    }
    int res = 0;
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;
    a = a > 0 ? -a : a;
    b = b > 0 ? -b : b;
    while (a <= b) {
      a -= b;
      res++;
    }
    return sign == 1 ? res : -res;
  }
};

int main(int argc, char *argv[]) { return 0; }