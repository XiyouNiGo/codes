#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      vector<int> dp(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        if (i  == 0 || dp[i - 1] < 0) dp[i] = nums[i];
        else dp[i] = dp[i - 1] + nums[i];
      }
      int max = INT_MIN;
      for (auto i : dp) {
        if (max < i) {
          max = i;
        }
      }
      return max;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
