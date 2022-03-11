#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
  int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left >= nums.size() || nums[left] != target ? -1 : left;
  }

  int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right < 0 || nums[right] != target ? -1 : right;
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return {left_bound(nums, target), right_bound(nums, target)};
  }
};

int main(int argc, char* argv[]) { return 0; }