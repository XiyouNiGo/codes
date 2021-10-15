#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      vector<int> counts(32);
      for (auto num : nums) {
        for (int i = 0; i < 32; i++) {
          counts[i] += num & 1;
          num >>= 1;
        }
      }
      long temp = 1;
      int res = 0;
      for (int i = 0; i < 32; i++) {
        if (counts[i] % 3) {
          res |= temp;
        }
        temp <<= 1;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
