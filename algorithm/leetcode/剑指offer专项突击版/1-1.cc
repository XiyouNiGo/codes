#include <bits/stdc++.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  // 用减法模拟（没有考虑边界情况）
  int divide(int a, int b) {
    int res = 0;
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;
    a = abs(a);
    b = abs(b);
    while (a >= b) {
      a -= b;
      res++;
    }
    return sign == 1 ? res : -res;
  }
};

int main(int argc, char *argv[]) { return 0; }