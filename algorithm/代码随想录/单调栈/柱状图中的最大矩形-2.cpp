#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // DP
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> firstMinLeft(n), firstMinRight(n);
    firstMinLeft[0] = -1;
    firstMinRight[n - 1] = n;
    for (int i = 1; i < n; i++) {
      int j = i - 1;
      while (j >= 0 && heights[j] >= heights[i]) {
        j = firstMinLeft[j];
      }
      firstMinLeft[i] = j;
    }
    for (int i = n - 2; i >= 0; i--) {
      int j = i + 1;
      while (j < n && heights[j] >= heights[i]) {
        j = firstMinRight[j];
      }
      firstMinRight[i] = j;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      int sum = heights[i] * (firstMinRight[i] - firstMinLeft[i] - 1);
      res = max(sum, res);
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }