#include <bits/stdc++.h>

using namespace std;

class Solution {
    int merge_count(vector<int>& nums, int left, int mid, int right) {
      int count = 0;
      vector<int> nums_left(nums.begin() + left, nums.begin() + mid - 1);
      vector<int> nums_right(nums.begin() + mid, nums.begin() + right);
      nums.clear();
      int i = 0, j = 0;
      while (i < nums_left.size() && j < nums_right.size()) {
        if (nums_left[i] < nums_right[j]) {
          nums.push_back(nums_left[i]);
          i++;
        } else {
          nums.push_back(nums_right[j]);
          j++;
          count += mid - i;
        }
      }
      for (int k = i; k < nums_left.size(); k++) {
        nums.push_back(nums_left[k]);
      }
      for (int k = j; k < nums_right.size(); k++) {
        nums.push_back(nums_right[k]);
      }
      return count;
    }
    int merge_sort_count(vector<int>& nums, int left, int right) {
      if (left > right) {
        return 0;
      }
      int mid = left + (right - left) / 2;
      return merge_sort_count(nums, left, mid - 1) + merge_sort_count(nums, mid, right) +
        merge_count(nums, left, mid, right);
    }
public:
    int reversePairs(vector<int>& nums) {
      return merge_sort_count(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
