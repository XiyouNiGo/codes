#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n][2];
    for (int i = +0; i < n; ++i) {
      if (i == 0) {
        dp[i][0] = 0;
        dp[i][1] = -prices[i];
      } else {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 只能买卖一次
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
      }
    }
    return dp[n - 1][0];
  }
};

int main(int argc, char* argv[]) { return 0; }