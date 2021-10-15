/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-05 21:17:59
 * @LastEditTime: 2021-10-06 11:44:08
 * @Description: file content
 * @FilePath: /leetcode/week6/931-1.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    // Variable-sized object may not be initialized
    // int dp[row][col] = {0};
    int dp[row][col];
    for (int j = 0; j < col; j++) {
      dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < row; i++) {
      for (int j = 0; j < col; j++) {
        dp[i][j] = matrix[i][j] + dp[i - 1][j];
        if (j > 0) {
          dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]);
        }
        if (j < col - 1) {
          dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);
        }
      }
    }
    return *min_element(dp[col - 1], dp[col]);
  }
};

int main(int argc, char *argv[]) { return 0; }