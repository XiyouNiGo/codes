/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 19:33:43
 * @LastEditTime: 2021-10-06 19:50:25
 * @Description: file content
 * @FilePath: /leetcode/week6/416-2.cpp
 */
#include <bits/stdc++.h>

#include <numeric>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum = sum / 2;
    // 状态压缩
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      // 必须从后向前
      for (int j = sum; j >= 0; j--) {
        if (j - nums[i] >= 0) {
          dp[j] = dp[j] | dp[j - nums[i]];
        }
      }
    }
    return dp[sum];
  }
};

int main(int argc, char* argv[]) { return 0; }