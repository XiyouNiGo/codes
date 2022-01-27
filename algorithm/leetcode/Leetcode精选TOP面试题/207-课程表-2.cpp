#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<vector<int>> edges;  // 邻接矩阵
  vector<int> indeg;          // 入度

  // 解法二： 拓扑排序（BFS）
  // O(N + M) O(N + M)
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    indeg.resize(numCourses);
    for (const auto& info : prerequisites) {
      edges[info[1]].push_back(info[0]);
      ++indeg[info[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }

    // 优化：不用一个存放拓扑序列的数组，只需记录序列中顶点数量即可
    int visited = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : edges[u]) {
        --indeg[v];
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
      ++visited;
    }

    return visited == numCourses;
  }
};

int main(int argc, char* argv[]) { return 0; }