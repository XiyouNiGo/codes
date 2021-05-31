#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      int size = 1;
      for (int i = 2; i <= nums.size(); i++) {
        size *= i;
      }
      res.reserve(size);
      backtrack(nums, 0);
      return res;
    }
private:
    set<vector<int>> visited;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
      if (start == nums.size()) {
        if (!visited.count(nums)) {
          visited.insert(nums);
          res.push_back(nums);
        }
        return;
      }
      for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1);
        swap(nums[i], nums[start]);
      }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 2, 1, 1};
    Solution().permuteUnique(nums);
    return 0;
}
