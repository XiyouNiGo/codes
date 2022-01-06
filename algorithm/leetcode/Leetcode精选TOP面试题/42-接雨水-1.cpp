#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
 public:
  // 解法一：单调栈
  int trap(vector<int>& height) {
    int n = height.size();
    stack<int> s;  // 递减栈，存放下标而不是值
    vector<int> next_great(n);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && height[s.top()] < height[i]) {
        s.pop();
      }
      next_great[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    for (auto ng : next_great) {
      cout << ng << endl;
    }

    int res = 0, i = 0;
    // for循环每次都会++，这种题目用while控制来的方便点
    while (i < n) {
      cout << "loop" << endl;
      if (next_great[i] != -1) {
        int begin = i, end = next_great[i];
        printf("begin = %d, end = %d, height = %d\n", begin, end,
               height[begin]);
        res += height[begin] * (end - begin - 1);
        while (++i < end) {
          cout << "here" << endl;
          res -= height[i];
        }
      } else {
        i++;
      }
    }
    cout << res << endl;
    return res;
  }
};

int main(int argc, char* argv[]) {
  // vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> h = {2, 0, 2};
  vector<int> h = {4, 2, 3};
  Solution().trap(h);
  return 0;
}