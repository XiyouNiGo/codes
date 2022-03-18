#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode *build(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return nullptr;
    }
    auto mid =
        max_element(nums.begin() + left, nums.begin() + right) - nums.begin();
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = build(nums, left, mid);
    node->right = build(nums, mid + 1, right);
    return node;
  }

 public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return build(nums, 0, nums.size());
  }
};

int main(int argc, char *argv[]) { return 0; }