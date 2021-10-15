#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int dp[n][2];
        //base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        //i=0的情况单独讨论
        for (int i = 1; i < n; i++) {
            //化简，消去k
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
    //新状态只和前一个状态有关，把空间复杂度降到O(1)
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        //base case
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; i++) {
            //化简，消去k
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};
