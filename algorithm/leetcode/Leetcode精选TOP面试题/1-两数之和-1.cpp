#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 暴力枚举
  // Time: O(N^2)
  // Space: O(1)
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

int main(int argc, char* argv[]) { return 0; }