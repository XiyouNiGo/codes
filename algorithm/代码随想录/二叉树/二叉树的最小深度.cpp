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
  // O(N) O(logN)
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right != nullptr) {
      return minDepth(root->right) + 1;
    }
    if (root->right == nullptr && root->left != nullptr) {
      return minDepth(root->left) + 1;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};

int main(int argc, char *argv[]) { return 0; }