#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j) {
      if (nums[i] * nums[i] > nums[j] * nums[j]) {
        res[k] = nums[i] * nums[i];
        i++;
      } else {
        res[k] = nums[j] * nums[j];
        j--;
      }
      k--;
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }