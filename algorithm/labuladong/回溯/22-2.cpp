#include <bits/stdc++.h>

using namespace std;

class Solution {
  void backtrack(vector<string>& res, string& cur, int open, int close, int n) {
    if (cur.size() == n * 2) {
      res.push_back(cur);
      return;
    }
    // 剪枝
    if (open < n) {
      cur.push_back('(');
      backtrack(res, cur, open + 1, close, n);
      cur.pop_back();
    }
    if (close < open) {
      cur.push_back(')');
      backtrack(res, cur, open, close + 1, n);
      cur.pop_back();
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string current;
    backtrack(res, current, 0, 0, n);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }