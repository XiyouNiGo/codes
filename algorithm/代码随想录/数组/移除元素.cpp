#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 双指针：O(N) O(1)
  int removeElement(vector<int>& nums, int val) {
    int slow = 0, n = nums.size();
    for (int fast = 0; fast < n; fast++) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
    }
    return slow;
  }
};

int main(int argc, char* argv[]) { return 0; }