/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 20:58:11
 * @LastEditTime: 2021-10-06 20:59:53
 * @Description: file content
 * @FilePath: /leetcode/week6/518-2.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 完全背包问题（物品数量无限）
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 1; j <= amount; j++)
        if (j - coins[i] >= 0) dp[j] = dp[j] + dp[j - coins[i]];

    return dp[amount];
  }
};

int main(int argc, char* argv[]) { return 0; }