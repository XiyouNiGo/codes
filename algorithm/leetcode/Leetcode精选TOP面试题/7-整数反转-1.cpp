#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 数学
  // O(logN) O(1)
  int reverse(int x) {
    int res = 0;
    // 负数同样适用
    while (x) {
      if (res < INT_MIN / 10 || res > INT_MAX / 10) {
        return 0;
      }
      int digit = x % 10;
      x /= 10;
      res = res * 10 + digit;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }