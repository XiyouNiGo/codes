/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-15 12:06:25
 * @LastEditTime: 2021-10-15 12:39:40
 * @Description: file content
 * @FilePath: /acwing/5-1.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>

using namespace std;

const int MAXSSIZE = 2005;
const int MAXNSIZE = 1005 * log(MAXSSIZE);  // N * logS
const int MAXVSIZE = 2005;

int main(int argc, char *argv[]) {
  int v[MAXNSIZE];
  int w[MAXNSIZE];
  int f[MAXVSIZE];
  int n = 0, m = 0;
  cin >> n >> m;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    int vi = 0, wi = 0, si = 0;
    cin >> vi >> wi >> si;
    int base = 1;
    while (base <= si) {
      count++;
      v[count] = vi * base;
      w[count] = wi * base;
      si -= base;
      base *= 2;
    }
    if (si > 0) {
      count++;
      v[count] = vi * si;
      w[count] = wi * si;
    }
  }

  // O(N*M) O(M)
  for (int i = 1; i <= count /* 注意是count而不是n */; i++) {
    for (int j = m; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  cout << f[m] << endl;
  return 0;
}