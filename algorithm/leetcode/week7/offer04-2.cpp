/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-21 21:15:55
 * @LastEditTime: 2021-10-21 22:21:19
 * @Description: file content
 * @FilePath: /algorithm/leetcode/week7/offer04-2.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    // 二分
    // O(logn*logm)
    return matrix.size() ? Helper(matrix, 0, matrix.size() - 1, 0,
                                  matrix[0].size() - 1, target)
                         : 0;
  }

 private:
  bool Helper(vector<vector<int>>& matrix, int top, int bottom, int left,
              int right, int target) {
    while (top <= bottom && left <= right) {
      int mid_i = top + (bottom - top) / 2, mid_j = left + (right - left) / 2;
      if (matrix[mid_i][mid_j] == target) {
        return true;
      } else if (matrix[mid_i][mid_j] < target) {
        // 排除左上角，处理右上角
        if (Helper(matrix, top, mid_i, mid_j + 1, right, target)) {
          return true;
        }
        // 合并左下角和右下角
        top = mid_i + 1;
      } else {
        // 排除右下角，处理左下角
        if (Helper(matrix, mid_i, bottom, left, mid_j - 1, target)) {
          return true;
        }
        // 合并左上角和右上角
        bottom = mid_i - 1;
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) { return 0; }
