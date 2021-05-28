#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      // 线性查找（每次查找右上角数字）
      int rows = matrix.size();
      if (rows == 0)
        return false;
      int cols = matrix[0].size();
      if (cols == 0)
        return false;
      int row = 0, col = cols - 1;
      int num;
      while (row < rows && col >= 0) {
        num = matrix[row][col];
        if (num == target)
          return true;
        else if (num > target) {
          --col;
        } else {
          ++row;
        }
      }
      return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
