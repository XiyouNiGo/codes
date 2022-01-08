#include "sort/bubble_sort.h"

using namespace std;

// O(N^2) O(1) in-place 稳定
void BubbleSort(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
      }
    }
  }
}