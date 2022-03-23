#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) {
      return "";
    }
    int dp[n][n];
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    int begin = 0, len = 1;
    for (int j = 1; j < n; j++) {
      for (int i = 0; i < j; i++) {
        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          dp[i][j] = j != i + 1 ? dp[i + 1][j - 1] : true;
        }
        if (dp[i][j] && j - i + 1 > len) {
          begin = i;
          len = j - i + 1;
        }
      }
    }
    return s.substr(begin, len);
  }
};

int main(int argc, char *argv[]) { return 0; }