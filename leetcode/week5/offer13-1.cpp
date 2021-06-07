#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<bool>> visited;
    inline int sum(int num, int snum) {
      return (num % 10 != 0) ? (snum + 1) : (snum - 8);
    }
    int dfs(int i, int j, int si, int sj, int m, int n, int k) {
      if (si + sj > k || i >= m || j >= n || visited[i][j]) {
        return 0;
      }
      visited[i][j] = true;
      return 1 + dfs(i + 1, j, sum(i + 1, si), sj, m, n, k) + dfs(i, j + 1, si, sum(j + 1, sj), m, n, k);
    }
public:
    int movingCount(int m, int n, int k) {
      visited = vector<vector<bool>>(m, vector<bool>(n, false));
      return dfs(0, 0, 0, 0, m, n, k);
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().movingCount(2, 3, 1) << endl;
    return 0;
}
