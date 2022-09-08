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
  // 类似层次遍历
  bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
      TreeNode* left = q.front();
      q.pop();
      TreeNode* right = q.front();
      q.pop();
      if (!left && !right) {
        continue;
      }
      if ((!left || !right || (left->val != right->val))) {
        return false;
      }
      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }
    return true;
  }
};

int main(int argc, char* argv[]) { return 0; }