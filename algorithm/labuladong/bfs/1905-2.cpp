#include <bits/stdc++.h>

#include <queue>
#include <utility>

using namespace std;

class Solution {
  const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool valid(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
      return false;
    }
    return true;
  }

  bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
           int j) {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    grid2[i][j] = 0;
    bool is_sub = grid1[i][j];
    while (!q.empty()) {
      int n = q.size();
      for (int k = 0; k < n; k++) {
        auto front = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
          int x = directions[d][0] + front.first;
          int y = directions[d][1] + front.second;
          if (valid(grid2, x, y) && grid2[x][y]) {
            // 入时判断
            q.emplace(x, y);
            grid2[x][y] = 0;
            if (grid1[x][y] == 0) {
              is_sub = false;
            }
          }
        }
      }
    }
    return is_sub;
  }

 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int n = grid1.size(), m = grid1[0].size();
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid2[i][j] && bfs(grid1, grid2, i, j)) {
          count++;
        }
      }
    }
    return count;
  }
};

int main(int argc, char* argv[]) { return 0; }