/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-08 11:42:26
 * @LastEditTime: 2021-10-08 18:14:35
 * @Description: file content
 * @FilePath: /leetcode/week6/1140-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<int> prefix(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // dp[i][m]表示从位置i开始,M =
    // m的情况下，第一位抓的玩家所能获取的最大数量石头

    for (int i = 0; i < n; ++i) prefix[i + 1] = piles[i] + prefix[i];
    for (int i = n - 1; i >= 0; --i) {
      for (int m = 1; m <= n; ++m) {
        int border = min(2 * m, n - i);
        for (int j = 1; j <= border; ++j) {
          dp[i][m] =
              max(dp[i][m], prefix[n] - prefix[i] - dp[i + j][max(j, m)]);
        }
      }
    }

    return dp[0][1];
  }
};
int main(int argc, char* argv[]) { return 0; }