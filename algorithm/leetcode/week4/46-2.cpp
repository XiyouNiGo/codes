#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int> track;
      backtrack(nums, track);
      return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& track) {
      if (track.size() == nums.size()) {
        res.push_back(track);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        bool valid = true;
        for (auto t : track) {
          if (t == nums[i]) {
            valid = false;
          }
        }
        if (valid) {
          track.push_back(nums[i]);
          backtrack(nums, track);
          track.pop_back();
        }
      }
    }
};


int main(int argc, char *argv[])
{
    return 0;
}
