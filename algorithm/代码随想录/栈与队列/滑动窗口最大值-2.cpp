#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 单调栈O（N） O(K)
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    // 单调递增，存的是下标
    deque<int> q;
    for (int i = 0; i < k; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    vector<int> res = {nums[q.front()]};
    for (int i = k; i < n; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() <= i - k) {
        q.pop_front();
      }
      res.push_back(nums[q.front()]);
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }