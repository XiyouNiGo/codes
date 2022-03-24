#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // O(N) O(N)
  int longestValidParentheses(string s) {
    int res = 0, n = s.length();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          // 内部无括号
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
          // 内部有括号
          dp[i] = dp[i - 1] +
                  ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        res = max(res, dp[i]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }