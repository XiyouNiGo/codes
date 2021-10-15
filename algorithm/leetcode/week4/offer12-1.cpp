#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k) {
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
        return false;
      }
      if (k == word.size() - 1) {
        return true;
      }
      board[i][j] = '\0';
      bool ret = backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i - 1, j, k + 1) ||
        backtrack(board, word, i, j + 1, k + 1) || backtrack(board, word, i, j - 1, k + 1);
      board[i][j] = word[k];
      return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (backtrack(board, word, i, j, 0)) {
            return true;
          }
        }
      }
      return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
