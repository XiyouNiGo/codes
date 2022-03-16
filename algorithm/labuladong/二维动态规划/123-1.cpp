#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n][3][2];
    for (int i = 0; i < n; ++i) {
      dp[i][0][0] = 0;
      dp[i][0][1] = -prices[i];
      for (int j = 2; j >= 1; --j) {
        if (i == 0) {
          dp[i][j][0] = 0;
          dp[i][j][1] = -prices[i];
        } else {
          // 一次买一次卖算一次交易次数
          dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
          dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        }
      }
    }
    return dp[n - 1][2][0];
  }
};

int main(int argc, char* argv[]) { return 0; }