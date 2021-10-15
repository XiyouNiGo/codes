#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; i++) {
            int t = dp_i_0;
            dp_i_0 = max(t, dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, t-prices[i]);
        }
        return dp_i_0;
    }
};
