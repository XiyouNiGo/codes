#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dp(nums, 0, memo);
    }
    //返回从dp[start]开始rob的最大金额数量
    int dp(vector<int>& nums, int start, vector<int>& memo) {
        if (start >= nums.size()) return 0;
        if (memo[start] != -1) return memo[start];
        return memo[start] = max(
                   //不抢
                   dp(nums, start + 1, memo),
                   //抢
                   dp(nums, start + 2, memo) + nums[start]
                  );
    }
    */
    /*
    //dp[i]:从第i间房开始rob的最大收益
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }
    */
    //只和最近两个状态有关
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp_i;
        int dp_i_1 = 0, dp_i_2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};
