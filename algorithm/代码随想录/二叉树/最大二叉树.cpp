#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* node = new TreeNode(0);
    if (nums.size() == 1) {
      node->val = nums[0];
      return node;
    }
    int maxValueIndex = max_element(nums.begin(), nums.end()) - nums.begin();
    int maxValue = nums[maxValueIndex];
    node->val = maxValue;

    if (maxValueIndex > 0) {
      vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
      node->left = constructMaximumBinaryTree(newVec);
    }
    if (maxValueIndex < (nums.size() - 1)) {
      vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
      node->right = constructMaximumBinaryTree(newVec);
    }
    return node;
  }
};

int main(int argc, char* argv[]) { return 0; }