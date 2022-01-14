#include <bits/stdc++.h>

#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool valid(const vector<vector<char>>& grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (valid(grid, i, j) == false || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    for (auto& d : directions) {
      int new_i = d.first + i;
      int new_j = d.second + j;
      dfs(grid, new_i, new_j);
    }
  }

 public:
  // 解法一： DFS
  // O(M * N) O(M * N)
  int numIslands(vector<vector<char>>& grid) {
    int n1 = grid.size(), n2 = grid[0].size();
    int count = 0;
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (grid[i][j] == '1') {
          ++count;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};

int main(int argc, char* argv[]) { return 0; }