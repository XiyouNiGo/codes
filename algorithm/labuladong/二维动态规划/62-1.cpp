#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }