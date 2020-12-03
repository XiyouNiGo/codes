#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    //选择：选择不同硬币
    //状态：目标金额
    //dp[n]：凑金额n的最少硬币数量
    for (int i = 0; i < dp.size(); i++) {
        for (int coin : coins) {
            //状态转移方程
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}
