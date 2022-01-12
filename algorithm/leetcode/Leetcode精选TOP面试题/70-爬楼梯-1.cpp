#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 动态规划
  // O(N) O(1)
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    int dp_i = 0, dp_i_1 = 2, dp_i_2 = 1;
    for (int i = 3; i <= n; i++) {
      dp_i = dp_i_1 + dp_i_2;
      dp_i_2 = dp_i_1;
      dp_i_1 = dp_i;
    }
    return dp_i;
  }
};

int main(int argc, char *argv[]) { return 0; }