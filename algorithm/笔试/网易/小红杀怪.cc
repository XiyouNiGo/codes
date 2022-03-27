#include <bits/stdc++.h>

#include <climits>

using namespace std;

int main(int argc, char *argv[]) {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int dp[a + 1][b + 1];  // dp[i][j]: 血量分别为i,j的怪的最小击杀次数
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      } else {
        int min_times = INT_MAX;
        if (i >= x) {
          min_times = min(min_times, dp[i - x][j] + 1);
        }
        if (j >= x) {
          min_times = min(min_times, dp[i][j - x] + 1);
        }
        if (i >= y && j >= y) {
          min_times = min(min_times, dp[i - y][j - y] + 1);
        }
        dp[i][j] = min_times == INT_MAX ? 1 : min_times;
      }
    }
  }
  cout << dp[a][b];
  return 0;
}