/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 21:12:51
 * @LastEditTime: 2021-10-06 21:15:14
 * @Description: file content
 * @FilePath: /leetcode/week6/191-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    for (; n != 0; n &= n - 1, count++);
    return count;
  }
};

int main(int argc, char *argv[]) { return 0; }