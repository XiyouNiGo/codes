#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
      if (b == 0) return a;
      return add(a ^ b, (a & b) << 1);
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().add(-1, -2) << endl;
    return 0;
}
