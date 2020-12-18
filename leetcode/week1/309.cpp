#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN, dp_pre_0 = 0;
        //还是不要单独讨论来得好（因为现在i-2需要讨论i=0和i=1的时候）
        for (int i = 0; i < n; i++) {
            int t = dp_i_0;
            dp_i_0 = max(t, dp_i_1+prices[i]);
            //因为有冷冻期，只能是前天卖股票
            dp_i_1 = max(dp_i_1, dp_pre_0-prices[i]);
            //昨天的dp_i_0赋给明天的dp_pre_0
            dp_pre_0 = t;
        }
        return dp_i_0;
    }
};
