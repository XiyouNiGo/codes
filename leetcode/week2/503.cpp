#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;   //单调栈
        map<int, int> m;
        vector<int> res(nums.size());
        for (int i = 0; i < 2 * nums.size() + 1; i++) {
            while (!s.empty() && nums[i % nums.size()] > s.top()) {
                m[s.top()] = nums[i % nums.size()];
                s.pop();
            }
            s.push(nums[i % nums.size()]);
        }
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = m.find(nums[i])->second;
        }
        return res;
    }
};
