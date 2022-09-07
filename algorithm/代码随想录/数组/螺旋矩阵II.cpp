#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1, num = 1;
    int times = (n + 1) / 2;
    vector<vector<int>> res(n, vector<int>(n));
    for (int t = 0; t < times; t++) {
      for (int i = left; i <= right - 1; i++) {
        res[top][i] = num;
        num++;
      }
      for (int i = top; i <= bottom - 1; i++) {
        res[i][right] = num;
        num++;
      }
      for (int i = right; i >= left + 1; i--) {
        res[bottom][i] = num;
        num++;
      }
      for (int i = bottom; i >= top + 1; i--) {
        res[i][left] = num;
        num++;
      }
      left++;
      right--;
      top++;
      bottom--;
    }
    if (n % 2) {
      res[n / 2][n / 2] = num;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }