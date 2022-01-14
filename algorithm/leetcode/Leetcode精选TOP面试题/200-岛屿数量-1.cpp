#include <bits/stdc++.h>

#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool valid(int i, int j, int n1, int n2) {
    return i >= 0 && i < n1 && j >= 0 && j < n2;
  }

 public:
  // 解法一： BFS
  // O(M * N) O(M * N)
  int numIslands(vector<vector<char>>& grid) {
    int n1 = grid.size(), n2 = grid[0].size();
    int count = 0;
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (grid[i][j] == '1') {
          ++count;
          queue<pair<int, int>> q;
          grid[i][j] = '0';
          q.push({i, j});
          while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
              pair<int, int> cur = q.front();
              q.pop();
              for (auto& d : directions) {
                int new_i = d.first + cur.first;
                int new_j = d.second + cur.second;
                if (valid(new_i, new_j, n1, n2) && grid[new_i][new_j] == '1') {
                  grid[new_i][new_j] = '0';
                  q.push({new_i, new_j});
                }
              }
            }
          }
        }
      }
    }
    return count;
  }
};

int main(int argc, char* argv[]) { return 0; }