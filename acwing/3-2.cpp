/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 12:45:03
 * @LastEditTime: 2021-10-14 12:54:38
 * @Description: file content
 * @FilePath: /acwing/3-2.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

const int MAXSIZE = 1005;
int v[MAXSIZE * MAXSIZE];
int w[MAXSIZE * MAXSIZE];
int f[MAXSIZE * MAXSIZE];

int main(int argc, char *argv[]) {
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }
  // 转化为01背包问题

  // O(N*M) O(M)
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  cout << f[m] << endl;
  return 0;
}