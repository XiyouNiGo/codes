#include <bits/stdc++.h>

using namespace std;

class Solution {
    inline int sum(int num, int snum) {
      return (num % 10 != 0) ? (snum + 1) : (snum - 8);
    }
public:
    int movingCount(int m, int n, int k) {
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<vector<int>> q;
      int count = 0;
      q.push({0, 0, 0, 0});
      while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
          auto temp = q.front();
          q.pop();
          if (temp[2] + temp[3] > k || temp[0] >= m || temp[1] >= n || visited[temp[0]][temp[1]]) {
            continue;
          }
          count++;
          visited[temp[0]][temp[1]] = true;
          q.push({temp[0] + 1, temp[1], sum(temp[0] + 1, temp[2]), temp[3]});
          q.push({temp[0], temp[1] + 1, temp[2], sum(temp[1] + 1, temp[3])});
        }
      }
      return count;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().movingCount(2, 3, 1) << endl;
    return 0;
}
