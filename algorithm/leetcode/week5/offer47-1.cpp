#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
      for (int i = 1; i < grid.size(); i++) {
        grid[i][0] += grid[i - 1][0];
      }
      for (int i = 1; i < grid[0].size(); i++) {
        grid[0][i] += grid[0][i - 1];
      }
      for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[0].size(); j++) {
          grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
      }
      return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
