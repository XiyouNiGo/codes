#include <bits/stdc++.h>

#include <climits>

using namespace std;

int main(int argc, char *argv[]) {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int max = INT_MIN, min = INT_MAX;
  int cnt = -1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (max < t - x || min > t + x) {
      cnt++;
      max = t + x;
      min = t - x;
    } else {
      vector<int> a = {t + x, t - x, min, max};
      sort(a.begin(), a.end());
      min = a[1];
      max = a[2];
    }
  }

  cout << cnt;
  return 0;
}