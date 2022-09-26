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
  int pre = -1, res = INT_MAX;
  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left);
    if (pre == -1) {
      pre = root->val;
    } else {
      res = min(res, root->val - pre);
      pre = root->val;
    }
    traverse(root->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    traverse(root);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }