#include <bits/stdc++.h>

#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
 public:
  // 解法二： 哈希表
  // Time: O(N)
  // Space: O(N)
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num2i;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      auto it = num2i.find(target - nums[i]);
      if (it != num2i.end()) {
        return {i, it->second};
      } else {
        num2i[nums[i]] = i;
      }
      // if (num2i.count(target - nums[i])) {
      //   return {i, num2i[target - nums[i]]};
      // } else {
      //   num2i[nums[i]] = i;
      // }
    }
    return {};
  }
};

int main(int argc, char* argv[]) {
  unordered_map<int, int> um;
  um.insert(make_pair(1, 2));
  if (um.count(1)) {
    cout << "1" << endl;
  } else {
    cout << "!1" << endl;
  }
  if (um.count(3)) {
    cout << "3" << endl;
  } else {
    cout << "!3" << endl;
  }
  return 0;
}