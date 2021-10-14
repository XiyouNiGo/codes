/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 12:30:31
 * @LastEditTime: 2021-10-14 12:39:54
 * @Description: file content
 * @FilePath: /acwing/2-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1005;
int v[MAXSIZE];
int w[MAXSIZE];
int f[MAXSIZE][MAXSIZE];

int main(int argc, char *argv[]) {
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j < v[i]) {
        f[i][j] = f[i - 1][j];
      } else {
        f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
      }
    }
  }

  cout << f[n][m] << endl;
  return 0;
}