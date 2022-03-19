// 3
// 5 10 8
// 5 8 7
// 2
// 15 22
// 1 4

#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <functional>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
  // input
  int n = 0, m = 0;
  scanf("%d", &n);
  int total[n], discount[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &total[i]);
    if (n > 0) {
      total[i] += total[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &discount[i]);
    if (n > 0) {
      discount[i] += discount[i - 1];
    }
  }
  scanf("%d", &m);
  vector<pair<int, int>> dc(m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &dc[i].second);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &dc[i].first);
  }

  // 降序排序（先按d，再按c）
  sort(dc.begin(), dc.end(), greater<pair<int, int>>());

  // output (BZM)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (total[i] >= dc[j].second) {
        total[i] -= dc[j].first;
        break;
      }
    }
    int dif = total[i] - discount[i];
    if (dif > 0) {
      printf("%c", 'Z');
    } else if (dif < 0) {
      printf("%c", 'M');
    } else {
      printf("%c", 'B');
    }
  }


  for (int i = 0; i < n; i++) {
    printf("%d %d\n", total[i], discount[i]);
  }
  return 0;
}