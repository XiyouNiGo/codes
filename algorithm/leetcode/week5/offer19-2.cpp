#include <bits/stdc++.h>

using namespace std;

// 题意改成：
// '%'用于匹配零个到多个任意字符
// '_'用于匹配一个任意字符
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
            dp[i][j] = dp[i - 1][j] || dp[i][j];
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

// Compare whether the text string s
// and the pattern string p match or not
int compare_like(const char *s, int sLen, const char *p, int pLen) {
  bool isMatch[sLen + 1][pLen + 1];
  for (int i = 0; i < sLen + 1; i++) {
    for (int j = 0; j < pLen + 1; j++) {
      if (i == 0 || j == 0) {
        isMatch[i][j] = (i == j);
        continue;
      }
      switch (p[j - 1]) {
        case '%':
          isMatch[i][j] = isMatch[i][j - 1] || isMatch[i - 1][j - 1];
          break;
        case '_':
          isMatch[i][j] = isMatch[i - 1][j - 1];
          break;
        default:
          isMatch[i][j] = isMatch[i - 1][j - 1] && s[i - 1] == p[j - 1];
          break;
      }
    }
  }
  return isMatch[sLen][pLen] ? 0 : -1;
}

int main(int argc, char *argv[]) {
  string s, p;
  cin >> s >> p;
  printf("%s comp %s: %d", s.c_str(), p.c_str(),
         compare_like(s.c_str(), s.size(), p.c_str(), p.size()));
  return 0;
}
