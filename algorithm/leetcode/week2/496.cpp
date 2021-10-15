#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
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
    */
    //从后往前（不用map）
    //从前往后入栈是能知道nextGreaterElement是哪个
    //但是不容易存到数组中（无法知道前置元素是第几号，
    //所以用map）
    //而从后往前，i指向元素就是map
    //通过栈也很容易知道nextGreaterElement是哪个
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res(nums1.size());
        vector<int> temp(nums2.size());
        //从后向前入栈
        for (int i = nums2.size() - 1; i >= 0; i--) {
            //弹出栈中较小元素，维护单调栈
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();
            temp[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    res[i] = temp[j];
                    break;
                }
            }
        }
        return res;    
    }
};
