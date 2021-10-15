#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //用哈希表解决
        //O(n)、O(n)
        //根据值找到索引i
        map<int, int> val2i;
        for (int i = 0; i < nums.size(); i++) {
            val2i[nums[i]] = i;
        }
        map<int, int>::iterator mi;
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if ( ( ( mi = val2i.find(left)) != val2i.end() ) && mi->second != i) {
                return vector<int>{i, mi->second};
            }
        }
        return vector<int>{-1, -1};
    }
};
