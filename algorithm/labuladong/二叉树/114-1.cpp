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
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    flatten(root->left);
    flatten(root->right);
    TreeNode *p = root, *q = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (p->right) {
      p = p->right;
    }
    p->right = q;
  }
};

int main(int argc, char *argv[]) { return 0; }