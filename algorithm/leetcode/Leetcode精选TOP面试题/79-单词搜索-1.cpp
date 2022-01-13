#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool valid(const vector<vector<char>>& board, int i, int j) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
  }

  bool backtrack(vector<vector<char>>& board, int i, int j, const string& word,
                 int index, vector<vector<bool>>& visited) {
    if (board[i][j] != word[index]) {
      return false;
    }
    if (index == word.size() - 1) {
      return true;
    }
    bool found = false;
    visited[i][j] = true;
    for (auto& d : directions) {
      int new_i = i + d.first, new_j = j + d.second;
      if (valid(board, new_i, new_j)) {
        if (visited[new_i][new_j] == false) {
          if (backtrack(board, new_i, new_j, word, index + 1, visited)) {
            found = true;
            break;
          }
        }
      }
    }
    visited[i][j] = false;  // remember to undo
    return found;
  }

 public:
  // 解法一： 回溯
  // O(M * N * 4^L) O(M * N)
  bool exist(vector<vector<char>>& board, string word) {
    int n1 = board.size(), n2 = board[0].size();
    vector<vector<bool>> visited(n1, vector<bool>(n2));
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (backtrack(board, i, j, word, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) { return 0; }