#include <bits/stdc++.h>

#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  long long n = 0, d = 0, count = 0;
  cin >> n >> d;
  vector<long long> stree(n);
  for (int i = 0; i < n; i++) {
    cin >> stree[i];
  }
  int left = 0, right = 2;
  while (left < n - 2) {
    while (right < n && stree[right] - stree[left] <= d) {
      right++;
    }
    if (right - left >= 3) {
      int len = right - left - 1;
      count += len * (len - 1);
    }
    left++;
  }
  printf("%lld", count % 99997867);
  return 0;
}