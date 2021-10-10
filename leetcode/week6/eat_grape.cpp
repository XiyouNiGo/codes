/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-10 17:39:27
 * @LastEditTime: 2021-10-10 17:49:55
 * @Description: file content
 * @FilePath: /leetcode/week6/eat_grape.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
 public:
  long eat_grape(long a, long b, long c) {
    long sum = a + b + c, max_elem = max(max(a, b), c), rest = sum - max_elem;
    if (2 * rest < max_elem) {
      return (rest + 1) / 2;
    } else {
      // 向上取整：2 = 3 - 1
      return (rest + 2) / 3;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }