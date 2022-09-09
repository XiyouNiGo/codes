#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) {
      return {};
    }
    backtrack(n, k, 1);
    return res;
  }

 private:
  vector<int> track;
  vector<vector<int>> res;
  void backtrack(int n, int k, int start) {
    if (track.size() == k) {
      res.push_back(track);
      return;
    }
    // 剪枝
    for (int i = start; i <= n - (k - track.size()) + 1; ++i) {
      track.push_back(i);
      backtrack(n, k, i + 1);
      track.pop_back();
    }
  }
};

int main(int argc, char *argv[]) { return 0; }