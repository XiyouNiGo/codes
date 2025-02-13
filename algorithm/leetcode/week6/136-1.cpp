/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 21:18:19
 * @LastEditTime: 2021-10-06 21:20:18
 * @Description: file content
 * @FilePath: /leetcode/week6/136-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto n : nums) {
      res ^= n;
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }