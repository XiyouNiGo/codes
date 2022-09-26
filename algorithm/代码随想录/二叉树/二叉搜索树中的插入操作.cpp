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
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }
    TreeNode *p = root, *pre = nullptr;
    while (p) {
      pre = p;
      if (p->val < val) {
        p = p->right;
      } else {
        p = p->left;
      }
    }
    if (pre->val < val) {
      pre->right = new TreeNode(val);
    } else {
      pre->left = new TreeNode(val);
    }
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }