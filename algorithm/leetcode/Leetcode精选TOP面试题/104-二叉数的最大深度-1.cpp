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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      bool all_nullptr = true;
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == nullptr) {
          continue;
        }
        all_nullptr = false;
        q.push(cur->left);
        q.push(cur->right);
      }
      if (all_nullptr == false) {
        depth++;
      }
    }
    return depth;
  }
};

int main(int argc, char *argv[]) { return 0; }