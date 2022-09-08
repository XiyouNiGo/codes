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
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == NULL) return 0;
    int tmp = 0;
    if (root->left != NULL && root->left->left == NULL &&
        root->left->right == NULL) {
      tmp = root->left->val;
    }
    return tmp + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

int main(int argc, char *argv[]) { return 0; }