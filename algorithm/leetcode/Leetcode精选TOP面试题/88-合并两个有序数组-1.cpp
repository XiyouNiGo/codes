#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 双指针
  // O(N + M) O(N + M)
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp(n + m);
    int p = 0, q = 0, cur = 0;
    while (p < m && q < n) {
      tmp[cur++] = nums1[p] < nums2[q] ? nums1[p++] : nums2[q++];
    }
    while (p < m) {
      tmp[cur++] = nums1[p++];
    }
    while (q < n) {
      tmp[cur++] = nums2[q++];
    }
    nums1 = tmp;
  }
};

int main(int argc, char* argv[]) { return 0; }