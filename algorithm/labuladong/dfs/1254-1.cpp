#include <bits/stdc++.h>

using namespace std;

class Solution {
  void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 1) {
      return;
    }
    grid[i][j] = 1;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }

 public:
  int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      dfs(grid, i, 0);
      dfs(grid, i, m - 1);
    }
    for (int i = 0; i < m; i++) {
      dfs(grid, 0, i);
      dfs(grid, n - 1, i);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          count++;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};

int main(int argc, char* argv[]) { return 0; }