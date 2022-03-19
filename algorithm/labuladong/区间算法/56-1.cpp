#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> v1, vector<int> v2) { return v1[0] < v2[0]; });
    vector<vector<int>> res;
    int low = 0, high = 0, i = 0;
    while (i < intervals.size()) {
      low = intervals[i][0];
      high = intervals[i][1];
      while (++i < intervals.size() && intervals[i][0] <= high) {
        high = max(high, intervals[i][1]);
      }
      res.push_back({low, high});
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }