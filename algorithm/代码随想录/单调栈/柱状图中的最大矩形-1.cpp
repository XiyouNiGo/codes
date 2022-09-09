#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 双指针：O（N^2）超时
  int largestRectangleArea(vector<int>& heights) {
    int sum = INT_MIN;
    for (int i = 0; i < heights.size(); i++) {
      int left = i, right = i;
      for (; left >= 0 && heights[left] >= heights[i]; left--) {
      }
      for (; right < heights.size() && heights[right] >= heights[i]; right++) {
      }
      sum = max(sum, (right - left - 1) * (heights[i]));
    }
    return sum;
  }
};

int main(int argc, char* argv[]) { return 0; }