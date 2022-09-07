#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, n = nums.size();
    int sum = 0, minLen = INT_MAX;
    while (right < n) {
      sum += nums[right];
      right++;
      while (sum >= target) {
        int len = right - left;
        minLen = std::min(minLen, len);
        sum -= nums[left];
        left++;
      }
    }
    return minLen == INT_MAX ? 0 : minLen;
  }
};

int main(int argc, char* argv[]) { return 0; }