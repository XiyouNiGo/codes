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
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != NULL) q.push(root);
    int res = 0;
    while (!q.empty()) {
      int size = q.size();
      res = q.front()->val;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }