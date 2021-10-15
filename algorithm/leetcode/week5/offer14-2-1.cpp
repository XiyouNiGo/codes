#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
      if (n <= 3) {
        return n - 1;
      }
      int n2 = 0, n3 = n / 3;
      if (n % 3 == 2) {
        n2 = 1;
      } else if (n % 3 == 1) {
        n3--;
        n2 = 2;
      }
      return pow(2, n2) * pow(3, n3);
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().cuttingRope(2) << endl;
    return 0;
}
