#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> nums;
    nums.resize(1001);
    for (int i = 0; i < trips.size(); i++) {
      nums[trips[i][1]] += trips[i][0];
      nums[trips[i][2]] -= trips[i][0];
    }
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      count += nums[i];
      if (count > capacity) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) { return 0; }