#include "sort/radix_sort.h"

#include <algorithm>

using namespace std;

// 基数排序：根据键值的每位数字来分配桶；
// 计数排序：每个桶只存储单一键值；
// 桶排序：每个桶存储一定范围的数值；

// O(D * (N + K)) O(K) out-place 稳定
// D为位数
void RadixSort(vector<int>& nums) {
  int n = nums.size();
  int max = *max_element(nums.begin(), nums.end());
  for (int radix = 1; radix <= max; radix *= 10) {
    vector<int> bucket(10, 0);
    for (int i = 0; i < n; i++) {
      bucket[(nums[i] / radix) % 10]++;
    }
    nums.clear();
    for (int i = 0; i < 10; i++) {
      while (bucket[i]--) {
        nums.push_back(i);
      }
    }
  }
}
