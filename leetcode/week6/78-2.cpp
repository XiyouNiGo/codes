#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    res.reserve(pow(2, nums.size()));
    backtrack(nums, 0);
    return res;
  }
private:
  vector<int> track;
  vector<vector<int>> res;
  void backtrack(vector<int> &nums, int start) {
    res.push_back(track);
    for (int i = start; i < nums.size(); ++i) {
      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums{1, 2, 3};
  Solution().subsets(nums);
  return 0;
}
