#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    if (k > nums.size()) {
      return false;
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // assert(sum % k == 0);
    if (sum % k) {
      return false;
    }
    bucket.resize(k);
    sort(nums.rbegin(), nums.rend());
    return backtrack(nums, 0, sum / k);
  }

 private:
  vector<int> bucket;
  bool backtrack(vector<int> &nums, int index, int target) {
    if (index >= nums.size()) {
      return (find_if_not(nums.begin(), nums.end(),
                          [=](int b) { return b == target; }) != nums.end());
    }
    // 以数字视角，数字选桶
    for (int i = 0; i < bucket.size(); i++) {
      if (nums[index] + bucket[i] > target) {
        continue;
      }
      bucket[i] += nums[index];
      if (backtrack(nums, index + 1, target)) {
        return true;
      }
      bucket[i] -= nums[index];
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums{1, 1, 1};
  cout << Solution().canPartitionKSubsets(nums, 3) << endl;
  return 0;
}
