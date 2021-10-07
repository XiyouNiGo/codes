/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 10:56:38
 * @LastEditTime: 2021-10-07 20:05:43
 * @Description: file content
 * @FilePath: /leetcode/week6/793-2.cpp
 */
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
 public:
  int preimageSizeFZF(int k) {
    // O(logN*logN)
    vector<long> nums(LONG_MAX);
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = i;
    }
    return upper_bound(nums.begin(), nums.end(), k, comp) - lower_bound(nums.begin(), nums.end(), k, comp) + 1;
    // Reference to non-static member function must be called
    // return upper_bound(0L, LONG_MAX, k, comp) - lower_bound(0L, LONG_MAX, k, comp) + 1;
  }

 private:
  static long trailingZeroes(long n) {
    long res = 0;
    long divisor = 5;
    while (divisor <= n) {
      res += n / divisor;
      divisor *= 5;
    }
    return res;
  }
  static bool comp(long l, long k) {
    return trailingZeroes(l) == k;
  }
};

int main(int argc, char *argv[]) {
  cout << Solution().preimageSizeFZF(0) << endl;
  return 0;
}