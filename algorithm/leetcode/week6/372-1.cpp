/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 21:17:40
 * @LastEditTime: 2021-10-07 21:46:23
 * @Description: file content
 * @FilePath: /leetcode/week6/372-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    if (b.empty()) {
      return 1;
    }
    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);
    return (part1 * part2) % kBase;
  }

 private:
  const int kBase = 1337;
  int mypow(int a, int k) {
    a %= kBase;
    int res = 1;
    for (int i = 0; i < k; i++) {
      res *= a;
      res %= kBase;
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }