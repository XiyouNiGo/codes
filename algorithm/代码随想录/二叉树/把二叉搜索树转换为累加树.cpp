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
 private:
  int pre = 0;
  void traverse(TreeNode *cur) {
    if (cur == NULL) return;
    traverse(cur->right);
    cur->val += pre;
    pre = cur->val;
    traverse(cur->left);
  }

 public:
  TreeNode *convertBST(TreeNode *root) {
    traverse(root);
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }