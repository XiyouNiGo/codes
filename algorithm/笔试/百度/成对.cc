#include <bits/stdc++.h>

#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  int T, N;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    int count = 1;
    for (int j = 2; j <= sqrt(N); j++) {
      if (N % j == 0) {
        int n1 = N / j, n2 = j;
        if (n1 < n2) {
          swap(n1, n2);
        }
        cout << n1 << " " << n2 << endl;
        for (int k = 2; k <= n2; k++) {
          if (n1 % k == 0 && n2 % k == 0) {
            continue;
          }
        }
        // cout << n1 << " " << n2 << endl;
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}