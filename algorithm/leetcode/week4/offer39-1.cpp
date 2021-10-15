#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ret, vote = 0;
      for (auto num : nums) {
        if (vote == 0) {
          vote++;
          ret = num;
        } else if (ret == num) {
          vote++;
        } else {
          vote--;
        }
      }
      return ret;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
