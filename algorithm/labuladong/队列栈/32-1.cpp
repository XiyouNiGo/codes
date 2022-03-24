#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  // O(N) O(N)
  int longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n + 1);
    // base case: dp[0] = 0
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
        // 左括号不可能为
        dp[i + 1] = 0;
      } else {
        if (!stk.empty()) {
          int left = stk.top();
          stk.pop();
          dp[i + 1] = i - left + 1 + dp[left];
        } else {
          dp[i + 1] = 0;
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

int main(int argc, char *argv[]) { return 0; }