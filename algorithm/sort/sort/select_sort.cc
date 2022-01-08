#include "sort/select_sort.h"

using namespace std;

// O(N^2) O(1) in-place 稳定
void SelectSort(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    int min_i = i;
    for (int j = i + 1; j < n; j++) {
      if (nums[min_i] > nums[j]) {
        min_i = j;
      }
    }
    swap(nums[min_i], nums[i]);
  }
}