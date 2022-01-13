#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<vector<string>> res;

  void backtrace(const vector<vector<bool>>& dp, vector<string>& track,
                 const string& s, int start) {
    int n = s.size();
    if (start >= n) {
      res.push_back(track);
      return;
    }
    for (int i = start; i < n; i++) {
      if (dp[start][i]) {
        track.push_back(s.substr(start, i - start + 1));
        backtrace(dp, track, s, i + 1);
        track.pop_back();
      }
    }
  }

 public:
  // 解法一： 回溯 + 动态规划预处理
  vector<vector<string>> partition(string s) {
    int n = s.size();
    // 动态规划预处理
    vector<vector<bool>> dp(n, vector<bool>(n));
    // TODO
    vector<string> track;
    backtrace(dp, track, s, 0);
  }
};

int main(int argc, char* argv[]) { return 0; }