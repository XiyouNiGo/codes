/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 18:19:29
 * @LastEditTime: 2021-10-06 19:51:21
 * @Description: file content
 * @FilePath: /leetcode/week6/416-1.cpp
 */
#include <bits/stdc++.h>

#include <numeric>

using namespace std;

class Solution {
 public:
  // 子集背包问题
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j - nums[i - 1] < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[n][sum];
  }
};

int main(int argc, char* argv[]) { return 0; }