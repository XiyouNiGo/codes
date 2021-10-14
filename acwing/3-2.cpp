/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-14 22:14:32
 * @LastEditTime: 2021-10-14 22:17:28
 * @Description: file content
 * @FilePath: /acwing/3-2.cpp
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

  // O(N*M) O(M)
  for (int i = 1; i <= n; i++) {
    // 跟01背包问题区别在于从前到后遍历
    for (int j = v[i]; j <= m; j++) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  cout << f[m] << endl;
  return 0;
}