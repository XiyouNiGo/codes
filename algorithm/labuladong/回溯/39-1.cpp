#include <bits/stdc++.h>

#include <vector>

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
      track.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i, track);
      track.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> track;
    backtrack(candidates, target, 0, track);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }