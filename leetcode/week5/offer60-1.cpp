#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<double> dicesProbability(int n) {
    vector<double> dp(6, 1.0 / 6.0);
    for (int i = 2; i <= n; i++) {
      vector<double> temp(5 * i + 1, 0);
      for (int j = 0; j < dp.size(); j++) {
        for (int k = 0; k < 6; k++) {
          temp[j + k] += dp[j] / 6.0;
        }
      }
      dp = temp;
    }
    return dp;
  }
};

int main(int argc, char *argv[])
{
    return 0;
}
