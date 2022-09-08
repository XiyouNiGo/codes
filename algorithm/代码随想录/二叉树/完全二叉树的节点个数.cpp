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
 public:
  // 利用满二叉树性质
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int leftDepth = 0, rightDepth = 0;
    while (left) {
      left = left->left;
      leftDepth++;
    }
    while (right) {
      right = right->right;
      rightDepth++;
    }
    if (leftDepth == rightDepth) {
      return (2 << leftDepth) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

int main(int argc, char* argv[]) { return 0; }