#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      if (x == 0) {
        return 0;
      }
      // 防止n为最小值
      double res = 1.0;
      long ln = n;
      if (ln < 0) {
        ln *= -1;
        x = 1.0 / x;
      }
      while (ln) {
        // % --> &
        // / --> >>
        if (ln & 1) {
          res *= x;
        }
        x *= x;
        ln >>= 1;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
