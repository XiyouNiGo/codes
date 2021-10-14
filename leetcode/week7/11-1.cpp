/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 19:50:59
 * @LastEditTime: 2021-10-14 19:52:45
 * @Description: file content
 * @FilePath: /leetcode/week7/11-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    while (left < right) {
      int area = min(height[left], height[right]) * (right - left);
      res = max(res, area);
      if (height[left] <= height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }