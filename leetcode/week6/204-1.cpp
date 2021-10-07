/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 20:08:54
 * @LastEditTime: 2021-10-07 20:16:53
 * @Description: file content
 * @FilePath: /leetcode/week6/204-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (IsPrime(i)) {
        count++;
      }
    }
    return count;
  }

 private:
  bool IsPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }