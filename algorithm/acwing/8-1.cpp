/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-15 13:31:06
 * @LastEditTime: 2021-10-15 13:37:07
 * @Description: file content
 * @FilePath: /acwing/8-1.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

const int MAXSIZE = 1005;
int v[MAXSIZE];
int m[MAXSIZE];
int w[MAXSIZE];
int f[MAXSIZE][MAXSIZE];

int main(int argc, char *argv[]) {
  int N = 0, V = 0, M = 0;
  cin >> N >> V >> M;
  for (int i = 1; i <= N; i++) {
    cin >> v[i] >> m[i] >> w[i];
  }

  // O(N*V*M) O(V*M)
  for (int i = 1; i <= N; i++) {
    for (int j = V; j >= v[i]; j--) {
      for (int k = M; k >= m[i]; k--) {
        f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
      }
    }
  }
  cout << f[V][M] << endl;
  return 0;
}