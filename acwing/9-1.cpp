/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-15 13:49:30
 * @LastEditTime: 2021-10-15 13:58:33
 * @Description: file content
 * @FilePath: /acwing/9-1.cpp
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 110;
int f[MAXSIZE];
int v[MAXSIZE][MAXSIZE], w[MAXSIZE][MAXSIZE], s[MAXSIZE];

int main() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i]; j++) {
      cin >> v[i][j] >> w[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      for (int k = 0; k < s[i]; k++) {
        if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}