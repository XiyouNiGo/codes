#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> res;
    unordered_set<int> hasExisted(nums1.begin(), nums1.end());
    for (int num : nums2) {
      if (hasExisted.find(num) != hasExisted.end()) {
        res.insert(num);
      }
    }
    return vector<int>(res.begin(), res.end());
  }
};

int main(int argc, char* argv[]) { return 0; }