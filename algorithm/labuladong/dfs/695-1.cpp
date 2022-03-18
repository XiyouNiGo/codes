#include <bits/stdc++.h>

using namespace std;

class Solution {
  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
      return 0;
    }
    grid[i][j] = 0;
    return dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) +
           dfs(grid, i, j - 1) + 1;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          res = max(res, dfs(grid, i, j));
        }
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }