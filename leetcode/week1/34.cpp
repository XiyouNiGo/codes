#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {left_bound(nums, target), right_bound(nums, target)};
    }
    //左侧边界（闭区间）
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] >= target) right = mid - 1;
        }
        if (left >= nums.size() || nums[left] != target) 
            return -1;
        return left;
    }
    //左侧边界（左闭右开区间）
    int left_bound2(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] >= target) right = mid;
        }
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }
    //右侧边界（闭区间）
    int right_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
        }
        if (left == 0 || nums[left - 1] != target)
            return -1;
        return left - 1;
    }
    //右侧边界（左闭右开区间）
    int right_bound2(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else if (nums[mid] > target) right = mid;
        }
        if (left == 0 || nums[left - 1] != target)
            return -1;
        return left - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s = Solution();
    vector<int> nums = {2, 3, 5, 6};
    cout << s.left_bound(nums, 5) << endl;
    cout << s.left_bound2(nums, 5) << endl;
    cout << s.right_bound(nums, 5) << endl;
    cout << s.right_bound2(nums, 5) << endl;
    return 0;
}
