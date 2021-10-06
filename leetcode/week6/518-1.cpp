/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 19:51:44
 * @LastEditTime: 2021-10-06 20:57:05
 * @Description: file content
 * @FilePath: /leetcode/week6/518-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 完全背包问题（物品数量无限）
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
      // dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (j - coins[i - 1] >= 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][amount];
  }
};

int main(int argc, char* argv[]) { return 0; }