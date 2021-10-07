/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 21:20:28
 * @LastEditTime: 2021-10-06 22:08:38
 * @Description: file content
 * @FilePath: /leetcode/week6/172-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trailingZeroes(int n) {
    int res = 0;
    long divisor = 5;
    while (divisor <= n) {
      res += n / divisor;
      divisor *= 5;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }