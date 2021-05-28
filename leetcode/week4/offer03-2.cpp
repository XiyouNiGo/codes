#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
      // 原地置换
      // O(N) O(1)
      int i = 0;
      while (i < nums.size()) {
        if (nums[i] == i) {
          i++;
          continue;
        } else if (nums[nums[i]] == nums[i]) {
          return nums[i];
        } else {
          swap(nums[i], nums[nums[i]]);
        }
      }
      return -1;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
