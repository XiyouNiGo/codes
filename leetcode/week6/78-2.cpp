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
    used.assign(nums.begin(), nums.end());
    return backtrack(k, 0, nums, 0, sum / k);
  }

 private:
  vector<bool> used;
  bool backtrack(int k, int bucket, vector<int> &nums, int start, int target) {
    // 以桶的视角
    // O(k*2^n)
    if (k == 0) {
      return true;
    }
    if (bucket == target) {
      return backtrack(k - 1, 0, nums, 0, target);
    }
    for (int i = start; i < nums.size(); i++) {
      used[i] = true;
      bucket += nums[i];
      if (backtrack(k, bucket, nums, i + 1, target)) {
        return true;
      }
      used[i] = false;
      bucket -= nums[i];
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums{1, 1, 1};
  cout << Solution().canPartitionKSubsets(nums, 3) << endl;
  return 0;
}