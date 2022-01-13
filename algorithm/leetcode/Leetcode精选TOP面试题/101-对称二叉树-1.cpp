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
  bool Recur(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    return p->val == q->val && Recur(p->left, q->right) &&
           Recur(p->right, q->left);
  }

 public:
  // 解法一： 递归
  // O(N) O(logN)
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return Recur(root->left, root->right);
  }
};

int main(int argc, char *argv[]) { return 0; }