#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    // dp[i[j]： s[i...j]是否为回文字符串
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }