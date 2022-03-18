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
  // 解法一： BFS
  // O(N) O(N)
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> temp;
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        temp.push_back(cur->val);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      if (temp.size()) {
        res.push_back(temp);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }