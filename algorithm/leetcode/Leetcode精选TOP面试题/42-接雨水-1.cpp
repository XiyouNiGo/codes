#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
 public:
  // 解法一：单调栈
  int trap(vector<int>& height) {
    int n = height.size();
    stack<int> stk;  // 递减栈，存放下标而不是值
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && height[stk.top()] < height[i]) {
        int top = stk.top();
        stk.pop();
        // 无法形成凹槽
        if (stk.empty()) {
          break;
        }
        // 只计算那一片长方形
        int right = stk.top();
        res += (right - i - 1) * (min(height[right], height[i]) - height[top]);
      }
      stk.push(i);
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  // vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> h = {2, 0, 2};
  vector<int> h = {4, 2, 3};  // 不能简单用NextGreateElement的思想来解决
  Solution().trap(h);
  return 0;
}