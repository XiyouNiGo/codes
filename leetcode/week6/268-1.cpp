/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 22:41:42
 * @LastEditTime: 2021-10-07 22:41:43
 * @Description: file content
 * @FilePath: /leetcode/week6/268-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &nums) {
  int n = nums.size();
  int res = 0;
  res ^= n;
  for (int i = 0; i < n; i++) res ^= i ^ nums[i];
  return res;
}

int main(int argc, char *argv[]) { return 0; }