#include <bits/stdc++.h>

#include <memory>

using namespace std;

class Solution {
 public:
  int minDistance(string a, string b) {
    // horse rose
    // rose -> hose -> horse
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), INT_MAX));
    dp[0][0] = a[0] == b[0] ? 0 : 1;
    for (int i = 1; i < a.size(); i++) {
      dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int j = 1; j < b.size(); j++) {
      dp[0][j] = dp[0][j - 1] + 1;
    }
    for (int i = 1; i < a.size(); i++) {
      for (int j = 1; j < b.size(); j++) {
        dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                       dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
      }
    }
    return dp.back().back();
  }
};

int main(int argc, char *argv[]) { return 0; }