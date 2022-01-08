#include <vector>

#include "sort/bucket_sort.h"

using namespace std;

void Recur(vector<int>& nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int basic = nums[left];
  int i = left /* 注意不是left + 1，试想一下两个数字的场景 */, j = right;
  while (i != j) {
    while (i != j && nums[j] >= basic) {
      j--;
    }
    while (i != j && nums[i] <= basic) {
      i++;
    }
    swap(nums[i], nums[j]);
  }
  swap(nums[left], nums[i]);
  Recur(nums, left, i - 1);
  Recur(nums, i + 1, right);
}

// O(N * logN) O(logN) in-place 不稳定
void QuickSort(vector<int>& nums) {
  int n = nums.size();
  Recur(nums, 0, n - 1);
}