#include <bits/stdc++.h>

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
 private:
  TreeNode* traverse(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + ((right - left) / 2);
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traverse(nums, left, mid - 1);
    root->right = traverse(nums, mid + 1, right);
    return root;
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traverse(nums, 0, nums.size() - 1);
    return root;
  }
};

int main(int argc, char* argv[]) { return 0; }