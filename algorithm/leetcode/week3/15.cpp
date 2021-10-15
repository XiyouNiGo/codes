#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> temp = twoSumTarget(nums, -nums[i], i);
            for (auto &t : temp) {
                t.push_back(nums[i]);
                res.push_back(t);
            }
            //保证target-nums[i]不同
            while ((i+1 < n) && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
    vector<vector<int>> twoSumTarget(vector<int>& nums, int target, int start) {
        int low = start, high = nums.size() - 1;
        vector<vector<int>> res;
        while (low < high) {
            int sum = nums[low] + nums[high];
            int left = nums[low], right = nums[high];
            if (sum == target) {
                res.push_back({left, right});
                while (low < high && nums[low] == left) low++;
                while (low < high && nums[high] == right) high--;
            }
            else if (sum < target) {
                while (low < high && nums[low] == left) low++;
            }
            else {
                while (low < high && nums[high] == right) high--;
            }
        }
        return res;
    }
};

