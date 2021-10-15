#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
      int temp = 0, res1 = 0, res2 = 0;
      for (auto num : nums) {
        temp ^= num;
      }
      int division = 1;
      while ((division & temp) == 0) {
        division <<= 1;
      }
      for (auto num : nums) {
        if (division & num) {
          res1 ^= num;
        } else {
          res2 ^= num;
        }
      }
      return {res1, res2};
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
