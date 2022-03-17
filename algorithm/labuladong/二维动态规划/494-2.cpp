#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
 public:
  // 0-1背包
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int& num : nums) {
      sum += num;
    }
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
      return 0;
    }
    int neg = diff / 2;
    vector<int> dp(neg + 1);  // 状态压缩
    dp[0] = 1;
    for (int& num : nums) {
      for (int j = neg; j >= num; j--) {
        dp[j] += dp[j - num];
      }
    }
    return dp[neg];
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 1, 1, 1, 1};
  cout << Solution().findTargetSumWays(nums, 3) << endl;
  return 0;
}