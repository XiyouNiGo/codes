#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  void backtrace(vector<int> &nums, int index) {
    res.push_back(path);
    for (int i = index; i < nums.size(); i++) {
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      backtrace(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    backtrace(nums, 0);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }