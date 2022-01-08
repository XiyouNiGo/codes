#include "sort/merge_sort.h"

#include <vector>

using namespace std;

// O(N * logN) O(N) out-place 稳定
static void Recur(vector<int>& nums, vector<int>& tmp, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  Recur(nums, tmp, left, mid);
  Recur(nums, tmp, mid + 1, right);
  // 归并
  int i = left, j = left, k = mid + 1;
  while (j <= mid && k <= right) {
    if (nums[j] < nums[k]) {
      tmp[i++] = nums[j++];
    } else {
      tmp[i++] = nums[k++];
    }
  }
  while (j <= mid) {
    tmp[i++] = nums[j++];
  }
  while (k <= right) {
    tmp[i++] = nums[k++];
  }
  for (i = left; i <= right; i++) {
    nums[i] = tmp[i];
  }
}

// O(N * logN) O(N) out-place 稳定
void MergeSort(vector<int>& nums) {
  int n = nums.size();
  vector<int> tmp(n);
  // 两边都是闭区间
  Recur(nums, tmp, 0, n - 1);
}
