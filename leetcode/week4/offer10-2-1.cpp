#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
      int a = 1, b = 1;
      int sum;
      for (int i = 0; i < n; i++) {
        // f(n) % p = {(f(n-1) % p) + (f(n-2) % p)}
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
      }
      return a;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
