#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 双指针
  // O(N) O(1)
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int slow = 0;
    for (int fast = 0; fast < nums.size() - 1; fast++) {
      if (nums[fast] != nums[fast + 1]) {
        nums[slow++] = nums[fast];
      }
    }
    nums[slow++] = nums.back();
    return slow;
  }
};

int main(int argc, char* argv[]) { return 0; }