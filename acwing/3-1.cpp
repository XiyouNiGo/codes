/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 12:41:31
 * @LastEditTime: 2021-10-14 12:44:38
 * @Description: file content
 * @FilePath: /acwing/3-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1005;
int f[MAXSIZE][MAXSIZE];
int v[MAXSIZE];
int w[MAXSIZE];

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }

  // O(N*M^2)
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k * v[i] <= j; k++) {
        // 挨个枚举
        f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << f[n][m] << endl;
  return 0;
}