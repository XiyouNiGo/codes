#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; i++) {
            int t = dp_i_0;
            //一笔交易只需一次fee,写上写下都可以
            dp_i_0 = max(t, dp_i_1+prices[i]-fee);
            dp_i_1 = max(dp_i_1, t-prices[i]);
        }
        return dp_i_0;
    }
};
