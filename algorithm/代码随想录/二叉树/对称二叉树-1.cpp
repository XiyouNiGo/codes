#include <bits/stdc++.h>

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
  bool helper(TreeNode *left, TreeNode *right) {
    return (left == nullptr && right == nullptr) ||
           (left != nullptr && right != nullptr && left->val == right->val &&
            helper(left->left, right->right) &&
            helper(left->right, right->left));
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    return helper(root->left, root->right);
  }
};

int main(int argc, char *argv[]) { return 0; }