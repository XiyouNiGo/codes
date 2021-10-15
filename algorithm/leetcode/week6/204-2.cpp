/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-07 20:16:58
 * @LastEditTime: 2021-10-07 20:50:37
 * @Description: file content
 * @FilePath: /leetcode/week6/204-2.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    int count = 0;
    vector<bool> is_prime(n, true);
    for (int i = 2; i < n; i++) {
      if (is_prime[i]) {
        count++;
        for (int j = i + i; j < n; j += i) {
          is_prime[j] = false;
        }
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  cout << Solution().countPrimes(10) << endl;
  return 0;
}