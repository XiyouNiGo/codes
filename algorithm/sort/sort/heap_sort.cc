#include "sort/heap_sort.h"

#include <vector>

using namespace std;

// 递推 O(1)
static void Heapify(vector<int>& nums, int n, int i) {
  int s1 = 2 * i + 1;
  int s2 = 2 * i + 2;
  while (s1 < n) {
    int max_i = i;  // 大顶堆
    if (s1 < n && nums[s1] > nums[max_i]) {
      max_i = s1;
    }
    if (s2 < n && nums[s2] > nums[max_i]) {
      max_i = s2;
    }
    if (max_i != i) {
      swap(nums[i], nums[max_i]);
      i = max_i;
      s1 = 2 * i + 1;
      s2 = 2 * i + 2;
    } else {
      break;
    }
  }
}

// 递归 O(logN)
// static void Heapify(vector<int>& nums, int n, int i) {
//   if (2 * i + 1 >= n) {
//     return;
//   }
//   int s1 = 2 * i + 1;
//   int s2 = 2 * i + 2;
//   int max_i = i;  // 大顶堆
//   if (s1 < n && nums[s1] > nums[max_i]) {
//     max_i = s1;
//   }
//   if (s2 < n && nums[s2] > nums[max_i]) {
//     max_i = s2;
//   }
//   if (max_i != i) {
//     swap(nums[i], nums[max_i]);
//     Heapify(nums, n, max_i);
//   }
// }

// O(N * logN) O(1) (递推) / O(logN) (递归) in-place 稳定
void HeapSort(vector<int>& nums) {
  int n = nums.size();
  // build heap
  // 从最后节点的父节点开始执行Heapify（叶子节点不需要做Heapify）
  // parent = (n - 1) / 2
  for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
    Heapify(nums, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(nums[0], nums[i]);
    Heapify(nums, i, 0);
  }
}