#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  // 解法一： 动态规划（状态压缩）
  // O(N) O(1)
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    // dp_i： 以第i个数结尾的连续子数组的最大和
    int max_res = INT_MIN, dp_i = 0;
    for (int i = 0; i < n; i++) {
      dp_i = max(dp_i + nums[i], nums[i]);
      max_res = max(dp_i, max_res);
    }
    return max_res;
  }
};

int main(int argc, char* argv[]) { return 0; }