#include <bits/stdc++.h>

#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> land(n, vector<int>(m, INT_MAX));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> land[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      } else {
        if (i > 0) {
          if (land[i - 1][j] != land[i][j]) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 2);
          } else {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
          }
        }
        if (j > 0) {
          if (land[i][j - 1] != land[i][j]) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 2);
          } else {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
          }
        }
      }
    }
  }
  cout << dp[n - 1][m - 1];
  return 0;
}