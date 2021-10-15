#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
      int slow = 0, fast = 0;
      while (fast < nums.size()) {
        if (nums[fast] & 1) {
          swap(nums[fast], nums[slow]);
          slow++;
        }
        fast++;
      }
      return nums;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
