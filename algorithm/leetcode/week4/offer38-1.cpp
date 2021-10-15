#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> permutation(string nums) {
      int size = 1;
      for (int i = 2; i <= nums.size(); i++) {
        size *= i;
      }
      res.reserve(size);
      backtrack(nums, 0);
      return res;
    }
private:
    set<string> visited;
    vector<string> res;
    void backtrack(string &nums, int start) {
      if (start == nums.size()) {
        if (!visited.count(nums)) {
          visited.insert(nums);
          res.push_back(nums);
        }
        return;
      }
      for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1);
        swap(nums[i], nums[start]);
      }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
