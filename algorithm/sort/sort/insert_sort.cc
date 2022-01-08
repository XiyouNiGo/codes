#include "sort/insert_sort.h"

using namespace std;

// O(N^2) O(1) in-place 稳定
void InsertSort(vector<int>& nums) {
  int n = nums.size();
  for (int i = 1; i < n; i++) {
    int j = 0;
    int tmp = nums[i];
    for (j = i - 1; j >= 0 && nums[j] > tmp; j--) {
      nums[j + 1] = nums[j];
    }
    nums[j + 1] = tmp;
  }
}