#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
    int low = start, high = nums.size() - 1;
    vector<vector<int>> res;
    while (low < high) {
      int sum = nums[low] + nums[high];
      int left = nums[low], right = nums[high];
      if (sum == target) {
        res.push_back({left, right});
        while (low < high && nums[low] == left) low++;
        while (low < high && nums[high] == right) high--;
      } else if (sum < target) {
        while (low < high && nums[low] == left) low++;
      } else {
        while (low < high && nums[high] == right) high--;
      }
    }
    return res;
  }

 public:
  // 双指针
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    // 由于要去重，所以需要排序
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      if (nums[i] > 0) {
        break;
      }
      vector<vector<int>> tmp = twoSum(nums, i + 1, -nums[i]);
      for (auto t : tmp) {
        res.push_back({nums[i], t[0], t[1]});
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }