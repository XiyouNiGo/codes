#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
  vector<vector<int>> res;

  void backtrack(vector<int>& candidates, int target, int start,
                 vector<int>& track) {
    if (target <= 0) {
      if (target == 0) {
        res.push_back(track);
      }
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
      // 这次如果选过了循环中就不能再选了
      if (i > start && candidates[i] == candidates[start]) {
        continue;
      }
      track.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i + 1, track);
      track.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> track;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, track);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }