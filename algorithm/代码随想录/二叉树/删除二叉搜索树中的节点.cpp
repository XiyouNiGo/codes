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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return root;
    if (root->val == key) {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->left == nullptr) {
        TreeNode *newRoot = root->right;
        delete root;
        return newRoot;
      } else if (root->right == nullptr) {
        TreeNode *newRoot = root->left;
        delete root;
        return newRoot;
      } else {
        TreeNode *cur = root->right;
        while (cur->left != nullptr) {
          cur = cur->left;
        }
        cur->left = root->left;
        TreeNode *tmp = root;
        root = root->right;
        delete tmp;
        return root;
      }
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    if (root->val < key) root->right = deleteNode(root->right, key);
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }