/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-05 15:28:30
 * @LastEditTime: 2021-10-05 21:06:40
 * @Description: file content
 * @FilePath: /leetcode/week6/773-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    queue<string> q;
    unordered_set<string> visited;
    string start;
    for (int i = 0; i < kRowSize; i++) {
      for (int j = 0; j < kColSize; j++) {
        start.push_back(board[i][j] + '0');
      }
    }
    int step = 0;
    q.push(start);
    visited.insert(start);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string cur = q.front();
        q.pop();
        if (cur == target) {
          return step;
        }
        int i0 = find(cur.begin(), cur.end(), '0') - cur.begin();
        for (int n : neighbor[i0]) {
          string new_board = cur;
          swap(new_board[n], new_board[i0]);
          if (!visited.count(new_board)) {
            q.push(new_board);
            visited.insert(new_board);
          }
        }
      }
      step++;
    }
    return -1;
  }

 private:
  const int kRowSize = 2;
  const int kColSize = 3;
  const string target = "123450";
  const vector<vector<int>> neighbor = {
      {1, 3}, {0, 4, 2}, {1, 5}, {0, 4}, {3, 1, 5}, {4, 2},
  };
};

int main(int argc, char* argv[]) {
  vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
  cout << Solution().slidingPuzzle(board) << endl;
  return 0;
}