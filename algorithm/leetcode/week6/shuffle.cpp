/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-08 10:39:38
 * @LastEditTime: 2021-10-08 10:45:32
 * @Description: file content
 * @FilePath: /leetcode/week6/shuffle.cpp
 */
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void shuffle(vector<int> &arr) {
    int n = arr.size();
    // 必须有且仅有n!种可能
    for (int i = n - 1; i >= 0; i--) swap(arr[i], arr[rand() % i]);
    // random_shuffle(arr.begin(), arr.end());
  }
};

int main(int argc, char *argv[]) { return 0; }