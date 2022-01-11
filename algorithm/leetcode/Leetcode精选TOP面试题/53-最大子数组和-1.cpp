#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  // 解法一： 动态规划
  // O(N) O(N)
  int maxSubArray(vector<int>& nums) {
    // dp[i]： 以第i个数结尾的连续子数组的最大和
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }
    // 结果未必是dp[n - 1]
    return *max_element(dp.begin(), dp.end());
  }
};

int main(int argc, char* argv[]) { return 0; }