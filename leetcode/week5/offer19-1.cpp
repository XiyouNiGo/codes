#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j == 0) {
          dp[i][j] = (i == 0);
        } else if (p[j - 1] != '*') {
          if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
            dp[i][j] = dp[i - 1][j - 1];
          }
        } else {
          if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
            dp[i][j] = dp[i-1][j] || dp[i][j];
          }
          if (j >= 2) {
            dp[i][j] = dp[i][j - 2] || dp[i][j];
          }
        }
      }
    }
    return dp[n][m];
  }  
};

int main(int argc, char *argv[])
{
    return 0;
}
