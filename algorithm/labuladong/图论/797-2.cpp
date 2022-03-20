#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;

  void backtrack(vector<vector<int>>& graph, vector<int>& track, int index) {
    // 图论式遍历不会漏掉根节点（只管当前）
    track.push_back(index);  // 肯定是有效的
    if (index == graph.size() - 1) {
      res.push_back(track);
      track.pop_back();  // 走不到line20了，必须处理掉
      return;
    }
    for (auto& adj : graph[index]) {
      backtrack(graph, track, adj);
    }
    track.pop_back();
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> track;
    backtrack(graph, track, 0);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }