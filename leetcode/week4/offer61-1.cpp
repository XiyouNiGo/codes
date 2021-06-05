#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
      unordered_set<int> uset;
      int max = INT_MIN, min = INT_MAX;
      for (auto num : nums) {
        if (num == 0) {
          continue;
        }
        if (uset.count(num)) {
          return false;
        }
        max = std::max(max, num);
        min = std::min(min, num);
        uset.insert(num);
      }
      return max - min < 5;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
