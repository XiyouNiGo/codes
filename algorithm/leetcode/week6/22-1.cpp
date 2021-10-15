/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-04 23:14:08
 * @LastEditTime: 2021-10-05 11:41:01
 * @Description: solution of leetcode 22
 * @FilePath: /leetcode/week6/22-1.cpp
 */

#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    backtrack(n, n);
    return res;
  }

 private:
  string track;
  vector<string> res;
  void backtrack(int left, int right) {
    if (left < 0 || right < 0 || right < left) {
      return;
    }
    if (left == 0 && right == 0) {
      res.push_back(track);
    }

    track.push_back('(');
    backtrack(left - 1, right);
    track.pop_back();

    track.push_back(')');
    backtrack(left, right - 1);
    track.pop_back();
  }
};

int main(int argc, char *argv[]) { return 0; }