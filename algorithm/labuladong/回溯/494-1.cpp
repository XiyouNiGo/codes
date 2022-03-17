#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
  int count = 0;

  void backtrace(vector<int>& nums, int target, int index) {
    if (index == nums.size()) {
      if (target == 0) {
        count++;
      }
      return;
    }
    backtrace(nums, target + nums[index], index + 1);
    backtrace(nums, target - nums[index], index + 1);
  }

 public:
  // O(2^N) O(N)
  int findTargetSumWays(vector<int>& nums, int target) {
    backtrace(nums, target, 0);
    return count;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 1, 1, 1, 1};
  cout << Solution().findTargetSumWays(nums, 3) << endl;
  return 0;
}