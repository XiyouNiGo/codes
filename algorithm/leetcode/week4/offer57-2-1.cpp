#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
      int left = 1, right = 1;
      int sum = 0;
      vector<vector<int>> res;
      while (left <= target / 2) {
        sum += right;
        right++;
        while (sum >= target) {
          if (sum == target) {
            vector<int> temp;
            for (int i = left; i < right; i++) {
              temp.push_back(i);
            }
            res.push_back(temp);
          }
          sum -= left;
          left++;
        }
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    auto res = Solution().findContinuousSequence(9);
    for (auto i : res) {
      for (auto j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
    return 0;
}
