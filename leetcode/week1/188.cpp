#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n = 0) return 0;
        int K = k;
        //相当于infinity
        if (K > n/2) {
            int dp_i_0 = 0, dp_i_1 = -prices[0];
            for (int i = 1; i < n; i++) {
                int t = dp_i_0;
                dp_i_0 = max(t, dp_i_1+prices[i]);
                dp_i_1 = max(dp_i_1, t-prices[i]);
            }
            return dp_i_0;        
        }
        int dp[n][K+1][2];
        for (int i = 0; i < n; i++) {
            //base case
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            for (k = K; k >= 1; k--) {
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
};
