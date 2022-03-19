#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  // 32 / 34...
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int i = 0, count = 0, n = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](vector<int> v1, vector<int> v2) { return v1[0] < v2[0]; });
    int low = intervals[0][0];
    int high = intervals[0][1];
    while (++i < n) {
      if (low <= intervals[i][0] && high >= intervals[i][1]) {
        count++;
      } else if (high >= intervals[i][0]) {
        high = intervals[i][1];
      } else {
        low = intervals[i][0];
        high = intervals[i][1];
      }
    }
    return n - count;
  }
};

int main(int argc, char* argv[]) { return 0; }