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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != NULL) q.push(root);
    vector<vector<int>> res;
    while (!q.empty()) {
      int size = q.size();
      vector<int> tmp;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        tmp.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }