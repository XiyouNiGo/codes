#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum % 2 != 0) return false;
        sum /= 2;
        //dp[i][j]：前i个物品能否装满容量为j的背包
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        //base case
        for (int i = 0; i <= nums.size(); i++)
            dp[i][0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                if (j-nums[i-1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum];
    }
    */
    //状态压缩
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        vector<bool> dp(sum + 1, false);
        // base case
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
