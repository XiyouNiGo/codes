#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;

  void backtrack(vector<vector<int>>& graph, vector<int>& track, int index) {
    if (index == graph.size() - 1) {
      res.push_back(track);
      return;
    }
    for (auto& adj : graph[index]) {
      track.push_back(adj);
      backtrack(graph, track, adj);
      track.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    // 回溯式遍历会漏掉根节点，需要加上
    vector<int> track;
    track.push_back(0);
    backtrack(graph, track, 0);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }