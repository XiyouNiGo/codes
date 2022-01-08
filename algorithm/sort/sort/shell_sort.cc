#include "sort/shell_sort.h"

using namespace std;

// O(N ^ (1.3 ~ 2)) O(1) in-place 不稳定
void ShellSort(vector<int>& nums) {
  int n = nums.size();
  int increment = n / 2;
  while (increment > 0) {
    for (int i = 1; i < n; i += increment) {
      int j = 0;
      int tmp = nums[i];
      for (j = i - increment; j >= 0 && nums[j] > tmp; j -= increment) {
        nums[j + increment] = nums[j];
      }
      nums[j + increment] = tmp;
    }
    increment /= 2;
  }
}