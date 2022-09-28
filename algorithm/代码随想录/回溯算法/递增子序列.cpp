#include <bits/stdc++.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  void backtrace(vector<int>& nums, int start) {
    if (path.size() >= 2) {
      res.push_back(path);
    }
    unordered_set<int> used;
    for (int i = start; i < nums.size(); i++) {
      if (used.count(nums[i]) || (!path.empty() && nums[i] < path.back())) {
        continue;
      }
      used.insert(nums[i]);
      path.push_back(nums[i]);
      backtrace(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    backtrace(nums, 0);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }