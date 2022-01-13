#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 动态规划
  // O(N^2) O(N^2)
  // TODO： 做错了（为啥？？？）
  string longestPalindrome(string s) {
    int n = s.size();
    int max_len = 1, begin = 0;
    // dp[i[j]： s[i...j]是否为回文字符串
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    // 画出表格，发现从列开始计算
    for (int j = 1; j < n; j++) {
      for (int i = 0; i < j; i++) {
        // 长度小于等于3的串不用判断子串
        dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1]);
        if (dp[i][j] && j - i + 1 > max_len) {
          begin = i;
          max_len = j - i + 1;
        }
      }
    }
    return s.substr(begin, begin + max_len);
  }
};

int main(int argc, char *argv[]) { return 0; }