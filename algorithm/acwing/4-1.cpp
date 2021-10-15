/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 22:49:43
 * @LastEditTime: 2021-10-14 22:56:30
 * @Description: file content
 * @FilePath: /acwing/4-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 105;
int v[MAXSIZE];
int w[MAXSIZE];
int s[MAXSIZE];
int f[MAXSIZE][MAXSIZE];

int main(int argc, char *argv[]) {
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }

  // O(N*V*S)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= s[i] && j >= k * v[i]; k++) {
        f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }

  cout << f[n][m] << endl;
  return 0;
}