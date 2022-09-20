#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        for (int k = 1; i >= k; k += 2) {
          dp[i][j] += dp[i - k][j];
          dp[i][j] %= (1000000000 + 7);
        }
        for (int k = 1; j >= k; k += 2) {
          dp[i][j] += dp[i][j - k];
          dp[i][j] %= (1000000000 + 7);
        }
      }
    }
    cout << dp.back().back() << endl;
  }
  return 0;
}