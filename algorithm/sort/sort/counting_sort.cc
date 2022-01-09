#include "sort/counting_sort.h"

#include <algorithm>

using namespace std;

// O(N + K) O(K) out-place 稳定
void CountingSort(vector<int>& nums) {
  int min = *min_element(nums.begin(), nums.end()),
      max = *max_element(nums.begin(), nums.end());
  int bucket_size = max - min + 1;
  vector<int> bucket(bucket_size, 0);
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    bucket[nums[i] - min]++;
  }
  nums.clear();
  for (int i = 0; i < bucket_size; i++) {
    while (bucket[i]--) {
      nums.push_back(min + i);
    }
  }
}