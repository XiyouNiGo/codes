#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int K = 2;
        int dp[n][K+1][2];
        for (int i = 0; i < n; i++) {
            //base case
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            for (int k = K; k >= 1; k--) {
                //base case
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
        return dp[n-1][K][0];
    }
    //k=1或2，直接穷举
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int dp_i10 = 0, dp_i11 = INT_MIN;
        int dp_i20 = 0, dp_i21 = INT_MIN;
        for (int i = 0; i < n; i++) {
            //k=2计算放前面，因为它用到了旧的dp_i10
            dp_i20 = max(dp_i20, dp_i21 + prices[i]);
            dp_i21 = max(dp_i21, dp_i10 - prices[i]);
            dp_i10 = max(dp_i10, dp_i11 + prices[i]);
            dp_i11 = max(dp_i11, -prices[i]);
        }
        return dp_i20;
    }
};
