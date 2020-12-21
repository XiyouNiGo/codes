#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //计算nums2每个元素的nextGreaterElement，存在map中
        //从map中找出nums1的答案
        stack<int> s;   //单调栈
        map<int, int> m;
        vector<int> res(nums1.size());
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > s.top()) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m.find(nums1[i])->second;
        }
        return res;
    }
};
