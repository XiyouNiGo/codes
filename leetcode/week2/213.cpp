#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //防止越界
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2),
                   robRange(nums, 1, n - 1));
    }
    //返回[start, end]最优解
    int robRange(vector<int>& nums, int start, int end) {
        int dp_i = 0;
        int dp_i_1 = 0, dp_i_2 = 0;
        for (int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};
