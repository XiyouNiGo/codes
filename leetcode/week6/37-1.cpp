/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-04 18:27:38
 * @LastEditTime: 2021-10-04 23:08:17
 * @Description: file content
 * @FilePath: /leetcode/week6/37-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  const int kBoardSize = 9;
  void solveSudoku(vector<vector<char>> &board) {
    backtrack(0, 0, board);
  }
 private:
  bool IsValid(int row, int col, char c, vector<vector<char>> &board) {
    for (int i = 0; i < kBoardSize; i++) {
      if (board[row][i] == c || board[i][col] == c) {
        return false;
      }
      if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) {
        return false;
      }
    }
    return true;
  }
  bool backtrack(int row, int col, vector<vector<char>> &board) {
    if (col >= kBoardSize) {
      return backtrack(row + 1, 0, board);
    }
    if (row >= kBoardSize) {
      return true;
    }
    for (int i = row; i < kBoardSize; i++) {
      for (int j = col; j < kBoardSize; j++) {
        if (board[i][j] != '.') {
            return backtrack(i, j + 1, board);
        }
        for (char c = '1'; c <= '9'; c++) {
          if (IsValid(i, j, c, board)) {
            board[i][j] = c;
            if (backtrack(i, j + 1, board)) {
              return true;
            }
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) { return 0; }