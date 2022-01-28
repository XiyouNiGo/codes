#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法二： 动态规划
  // O(N) O(N)
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) {
      return 0;
    }
    vector<int> left_max(n);
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
      left_max[i] = max(left_max[i - 1], height[i]);
    }

    vector<int> right_max(n);
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right_max[i] = max(right_max[i + 1], height[i]);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += min(left_max[i], right_max[i]) - height[i];
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }