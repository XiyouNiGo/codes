/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 22:08:48
 * @LastEditTime: 2021-10-07 10:56:30
 * @Description: file content
 * @FilePath: /leetcode/week6/793-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int preimageSizeFZF(int k) {
    // O(logN*logN)
    return right_bound(k) - left_bound(k) + 1;
  }

 private:
  long trailingZeroes(long n) {
    long res = 0;
    long divisor = 5;
    while (divisor <= n) {
      res += n / divisor;
      divisor *= 5;
    }
    return res;
  }
  long left_bound(int k) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      if (trailingZeroes(mid) < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    // 必然能找到，因此不判断
    return left;
  }
  long right_bound(int k) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      if (trailingZeroes(mid) <= k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};

int main(int argc, char *argv[]) { return 0; }