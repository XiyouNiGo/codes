#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  //  0
  //  1
  // 10
  // 11
  //100
  vector<int> countBits(int n) {
    vector<int> dp(n + 1);
    int high_bit = 0;
    for (int i = 1; i <= n; i++) {
      if ((i & (i - 1)) == 0) {
        high_bit = i;
      }
      dp[i] = dp[i - high_bit] + 1;
    }
    return dp;
  }
};

int main(int argc, char *argv[]) { return 0; }