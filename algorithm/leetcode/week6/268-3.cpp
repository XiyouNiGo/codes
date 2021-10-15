/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 22:50:02
 * @LastEditTime: 2021-10-07 22:50:02
 * @Description: file content
 * @FilePath: /leetcode/week6/268-3.cpp
 */
#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> nums) {
    int n = nums.size();
    int res = 0;
    res += n - 0;
    for (int i = 0; i < n; i++) res += i - nums[i];
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }