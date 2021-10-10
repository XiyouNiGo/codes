/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-08 11:42:26
 * @LastEditTime: 2021-10-10 13:34:07
 * @Description: file content
 * @FilePath: /leetcode/week6/1140-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int len = piles.size(), sum = 0;
    vector<vector<int>> dp(len, vector<int>(len + 1));
    for (int i = len - 1; i >= 0; i--) {
      sum += piles[i];
      for (int M = 1; M <= len; M++) {
        if (i + 2 * M >= len) {
          dp[i][M] = sum;
        } else {
          for (int x = 1; x <= 2 * M; x++) {
            dp[i][M] = max(dp[i][M], sum - dp[i + x][max(M, x)]);
          }
        }
      }
    }
    return dp[0][1];
  }
};

int main(int argc, char* argv[]) { return 0; }