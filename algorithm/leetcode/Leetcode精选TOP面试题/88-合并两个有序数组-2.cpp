#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法二： 逆向双指针
  // O(N + M) O(1)
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m - 1, q = n - 1, cur = m + n - 1;
    nums1.resize(m + n);
    while (p >= 0 && q >= 0) {
      nums1[cur--] = nums1[p] > nums2[q] ? nums1[p--] : nums2[q--];
    }
    while (p >= 0) {
      nums1[cur--] = nums1[p--];
    }
    while (q >= 0) {
      nums1[cur--] = nums2[q--];
    }
  }
};

int main(int argc, char* argv[]) { return 0; }