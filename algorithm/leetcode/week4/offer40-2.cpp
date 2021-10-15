#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> quicksort(vector<int> &nums, int left, int right, int k) {
      if (left > right) {
        return {};
      }
      int i = left, j = right;
      while (i != j) {
        while (i != j && nums[j] > nums[left]) j--;
        while (i != j && nums[i] < nums[left]) i++;
        swap(nums[i], nums[j]);
      }
      swap(nums[i], nums[left]);
      if (i == k - 1) {
        return vector<int>(nums.begin(), nums.begin() + k);
      }
      return (i > k - 1) ? quicksort(nums, left, i - 1, k) : quicksort(nums, i + 1, right, k);
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      if (arr.size() == 0 || k <= 0) {
        return {};
      }
      return quicksort(arr, 0, arr.size() - 1, k);
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {3, 4, 1, 5, 2, 0};
    auto ret = Solution().getLeastNumbers(nums, 4);
    for (auto num : ret) {
      cout << num << endl;
    }
    return 0;
}
