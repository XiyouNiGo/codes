#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    int i1 = 0, i2 = 0;
    vector<vector<int>> res;
    while (i1 < firstList.size() && i2 < secondList.size()) {
      int l1 = firstList[i1][0], r1 = firstList[i1][1];
      int l2 = secondList[i2][0], r2 = secondList[i2][1];
      if (r1 < l2) {
        i1++;
      } else if (r2 < l1) {
        i2++;
      } else {
        res.push_back({max(l1, l2), min(r1, r2)});
        if (r1 < r2) {
          i1++;
        } else {
          i2++;
        }
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }