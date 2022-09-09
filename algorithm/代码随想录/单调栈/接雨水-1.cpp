#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 双指针（模拟）：O(N^2) O(1)
  int trap(vector<int>& height) {
    int sum = 0;
    for (int i = 0; i < height.size(); i++) {
      if (i == 0 || i == height.size() - 1) continue;

      int rHeight = height[i];
      int lHeight = height[i];
      for (int r = i + 1; r < height.size(); r++) {
        if (height[r] > rHeight) rHeight = height[r];
      }
      for (int l = i - 1; l >= 0; l--) {
        if (height[l] > lHeight) lHeight = height[l];
      }
      int h = min(lHeight, rHeight) - height[i];
      if (h > 0) sum += h;
    }
    return sum;
  }
};

int main(int argc, char* argv[]) { return 0; }