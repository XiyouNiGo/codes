/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-06 12:08:35
 * @LastEditTime: 2021-10-06 12:46:56
 * @Description: file content
 * @FilePath: /leetcode/week6/494-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // O(2^n)
  int findTargetSumWays(vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return 0;
    }
    backtrack(nums, 0, target);
    return res;
  }

 private:
  int res = 0;
  void backtrack(vector<int> &nums, int start, int rest) {
    if (start == nums.size()) {
      if (rest == 0) {
        res++;
      }
      return;
    }
    rest += nums[start];
    backtrack(nums, start + 1, rest);
    rest -= nums[start];

    rest -= nums[start];
    backtrack(nums, start + 1, rest);
    rest += nums[start];
  }
};

int main(int argc, char *argv[]) { return 0; }