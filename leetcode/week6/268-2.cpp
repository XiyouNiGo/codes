/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 22:43:59
 * @LastEditTime: 2021-10-07 22:47:48
 * @Description: file content
 * @FilePath: /leetcode/week6/268-2.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    // 可能溢出
    int expect = (0 + n) * (n + 1) / 2;
    int sum = 0;
    for (int x : nums) sum += x;
    return expect - sum;
  };
};

int main(int argc, char *argv[]) { return 0; }