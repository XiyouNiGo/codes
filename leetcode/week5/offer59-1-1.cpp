#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int left = 1 - k, right = 0;
      vector<int> res;
      deque<int> window;
      while (right < nums.size()) {
        int num = nums[right++];
        while (!window.empty() && window.back() < num) {
          window.pop_back();
        }
        window.push_back(num);
        if (right >= k) {
          res.push_back(window.front());
        }
        if (left >= 0) {
          if (nums[left] == window.front()) {
            window.pop_front();
          }
        }
        left++;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
   Solution().maxSlidingWindow(nums, 3);
  return 0;
}
