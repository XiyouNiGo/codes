#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<string>& board, int row, int col) {
    //由于决策树从上到下，无须判断下方是否冲突
    int n = board.size();
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    //右上角
    for (int i = row - 1, j = col + 1; 
            i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    //左上角
    for (int i = row - 1, j = col - 1;
            i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
//board:路径
//row: 第row行及之后的所有节点都是放置皇后的选择
void backtrack(vector<string>& board, int row, vector<vector<string>>& res) {
    int n = board.size();
    //结束条件
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        //排除不合法选择
        if (!isValid(board, row, col)) continue;
        //做选择
        board[row][col] = 'Q';
        backtrack(board, row+1, res);
        //撤销选择
        board[row][col] = '.';
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, res);
    return res;
}
