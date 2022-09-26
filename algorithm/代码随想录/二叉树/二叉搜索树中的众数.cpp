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
  vector<int> res;
  int base, count, maxCount;

  void update(int n) {
    if (n == base) {
      ++count;
    } else {
      count = 1;
      base = n;
    }
    if (count == maxCount) {
      res.push_back(base);
    } else if (count > maxCount) {
      maxCount = count;
      res = vector<int>{base};
    }
  }

  void dfs(TreeNode *root) {
    if (!root) {
      return;
    }
    dfs(root->left);
    update(root->val);
    dfs(root->right);
  }

  vector<int> findMode(TreeNode *root) {
    dfs(root);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }