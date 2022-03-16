#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // TODO: 没做出来...
  // 不满足无后效性，所以需要倒序dp
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    if (n == 0) {
      return 1;
    }
    int m = dungeon[0].size();
    // dp[i][j]: 从左上角走到(i,j)所需的最低点数
    // dungeon：从左上角走到(i,j)剩余的点数
    int dp[n][m];
    for (int i = 1; i < n; i++) {
      if (dungeon[i - 1][0] + dungeon[i][0] > 0) {
        dp[i][0] = dp[i - 1][0];
        dungeon[i][0] += dungeon[i - 1][0];
      } else {
        dp[i][0] = dp[i - 1][0] + (1 - dungeon[i][0] - dungeon[i - 1][0]);
        dungeon[i][0] = 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
          dungeon[i][j] += dp[i][j];
        } else {
          int min_dp1 = INT_MAX, min_dungeon1 = INT_MAX;
          int min_dp2 = INT_MAX, min_dungeon2 = INT_MAX;
          if (i > 0) {
            if (dungeon[i - 1][j] + dungeon[i][j] > 0) {
              min_dp1 = dp[i - 1][j];
              min_dungeon1 = dungeon[i][j] + dungeon[i - 1][j];
            } else {
              min_dp1 = dp[i - 1][j] + (1 - dungeon[i][j] - dungeon[i - 1][j]);
              min_dungeon1 = 1;
            }
          } else if (j > 0) {
            if (dungeon[i][j - 1] + dungeon[i][j] > 0) {
              min_dp2 = dp[i][j - 1];
              min_dungeon2 = dungeon[i][j] + dungeon[i][j - 1];
            } else {
              min_dp2 = dp[i][j - 1] + (1 - dungeon[i][j] - dungeon[i][j - 1]);
              min_dungeon2 = 1;
            }
          }
          if (min_dp1 < min_dp2 ||
              (min_dp1 == min_dp2 && min_dungeon1 >= min_dungeon2)) {
            dp[i][j] = min_dp1;
            dungeon[i][j] = min_dungeon1;
          } else {
            dp[i][j] = min_dp2;
            dungeon[i][j] = min_dungeon2;
          }
        }
      }
    }
    return dp[n - 1][m - 1];
  }
};

int main(int argc, char* argv[]) { return 0; }