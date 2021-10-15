#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  // O(n*2^n)
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res(1);  
    res.reserve(pow(2, nums.size()));  
    for (int i = 0; i < nums.size(); i++) {
      int size = res.size();
      for (int j = 0; j < size; j++) {
        // O(n)
        res.push_back(res[j]);
        // O(1)
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { 
  vector<int> nums{1, 2, 3};
  Solution().subsets(nums);
  return 0;
}
