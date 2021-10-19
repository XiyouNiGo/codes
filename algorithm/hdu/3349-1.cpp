/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-15 14:23:12
 * @LastEditTime: 2021-10-19 22:46:26
 * @Description: file content
 * @FilePath: /algorithm/hdu/3349-1.cpp
 */
#include <bits/stdc++.h>

using namespace std;

int c, w;
int f[100005], g[100005];

int main(int argc, char *argv[]) {
  int N = 0, V = 0;
  cin >> N >> V;
  for (int i = 0; i < N; i++) {
    int v = 0, M = 0;
    cin >> v >> M;
    // 先进行一次01背包，转化为V - v + 1件物品的分组
    // 分组物品价格保存在f中
    for (int j = 1; j <= M; j++) {
      // 只用一次，压缩之
      cin >> c >> w;
      for (int k = V - v; k >= c; k--) {
        f[k] = max(f[k], f[k - c] + w);
      }
    }
    // 由于不知道当前组最大元素，j无法优化，下界为0
    for (int j = V; j >= 0; j--) {
      // 注意k下标，因为可能不选择，因此需要f[0]
      for (int k = 0; k < V - v + 1; k++) {
        g[j] = max(g[j], g[j - f[k]] + w);
      }
    }
  }
  cout << g[V];
  return 0;
}