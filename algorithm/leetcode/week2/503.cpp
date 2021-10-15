#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n);
        //利用%模拟循环数组
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n])
                s.pop();
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;    
    }
};
