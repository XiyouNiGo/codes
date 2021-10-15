#include <bits/stdc++.h>

using namespace std;

// 交换法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      int size = 1;
      for (int i = 2; i <= nums.size(); i++) {
        size *= i;
      }
      res.reserve(size);
      backtrack(nums, 0);
      return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
      if (start == nums.size()) {
        res.push_back(nums);
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
    return 0;
}
