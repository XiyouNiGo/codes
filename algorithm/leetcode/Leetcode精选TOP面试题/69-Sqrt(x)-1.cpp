#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 二分查找
  // O(logN) O(1)
  int mySqrt(int x) {
    int left = 1, right = x;
    // 寻找右侧边界
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      if (mid * mid <= x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};

int main(int argc, char *argv[]) { return 0; }