#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

long dfs(int *ball, int n, int index, int k1, int k2, long &max, long &count) {
  if (index >= n) {
    return 0;
  }
  for (int i = index + 1; i < n; i++) {
    long sum = dfs(ball, n, i, k1, k2, max, count) + ball[index];
    if (sum % k1 == 0 && sum % k2) {
      if (sum == max) {
        count = (count + 1) % 998244353;
      } else if (sum > max) {
        count = 1;
        max = sum;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int n = 0, k1 = 0, k2 = 0;
  scanf("%d%d%d", &n, &k1, &k2);
  int ball[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ball[i]);
  }
  long max = LONG_MIN, count = 0;
  dfs(ball, n, 0, k1, k2, max, count);
  
  printf("%ld %ld", max, count % 998244353);
  return 0;
}