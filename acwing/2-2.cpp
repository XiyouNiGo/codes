/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 12:33:24
 * @LastEditTime: 2021-10-14 12:39:51
 * @Description: file content
 * @FilePath: /acwing/2-2.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

const int MAXSIZE = 1005;
int v[MAXSIZE];
int w[MAXSIZE];
int f[MAXSIZE];

int main(int argc, char *argv[]) {
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  cout << f[m] << endl;
  return 0;
}