#include <bits/stdc++.h>

#include <climits>

using namespace std;

class Solution {
 public:
  // 解法三： 双指针
  // O(N) O(1)
  int trap(vector<int>& height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    int left_max = INT_MIN, right_max = INT_MIN;
    // 起码有两个凹槽才能计算
    while (left < right) {
      left_max = max(left_max, height[left]);
      right_max = max(right_max, height[right]);
      if (height[left] < height[right]) {
        res += left_max - height[left];
        left++;
      } else {
        res += right_max - height[right];
        right--;
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }