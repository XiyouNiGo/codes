#include "sort/bucket_sort.h"

using namespace std;

// O(N + K) O(N + K) out-place 稳定
void BucketSort(vector<int>& nums, int min, int max) {
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