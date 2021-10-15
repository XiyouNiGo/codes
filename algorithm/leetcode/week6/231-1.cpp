/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 21:15:29
 * @LastEditTime: 2021-10-06 21:17:34
 * @Description: file content
 * @FilePath: /leetcode/week6/231-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return !(n &= n - 1);
  }
};

int main(int argc, char *argv[]) { return 0; }