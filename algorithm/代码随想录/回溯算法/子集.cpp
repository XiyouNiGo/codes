#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<vector<int>> result;
  vector<int> track;
  void backtrack(vector<int>& nums, int startIndex) {
    result.push_back(track);
    if (startIndex >= nums.size()) {
      return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, 0);
    return result;
  }
};

int main(int argc, char* argv[]) { return 0; }