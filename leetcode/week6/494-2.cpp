/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 12:08:35
 * @LastEditTime: 2021-10-06 15:22:07
 * @Description: file content
 * @FilePath: /leetcode/week6/494-2.cpp
 */
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > abs(sum)) {
      return 0;
    }
    int size = nums.size();
    int t = 2 * sum + 1;
    int dp[size][t];
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < t; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][sum + nums[0]]++;
    dp[0][sum - nums[0]]++;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < t; j++) {
        dp[i][j] = (j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : 0) +
                   (j + nums[i] < t ? dp[i - 1][j + nums[i]] : 0);
      }
    }
    return dp[size - 1][sum + target];
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 1, 1, 1, 1};
  cout << Solution().findTargetSumWays(nums, 3) << endl;
  return 0;
}