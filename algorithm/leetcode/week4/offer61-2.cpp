#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int joker = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
          joker++;
        } else if ((i < nums.size() - 1) && nums[i] == nums[i + 1]) {
          return false;
        }
      }
      return nums[4] - nums[joker] < 5;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
