#include <bits/stdc++.h>

#include <string>
#include <unordered_map>

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
  vector<TreeNode *> res;

  string dfs(unordered_map<string, int> &has_appeared, TreeNode *root) {
    if (root == nullptr) {
      return "";
    }
    string node = to_string(root->val) + "," + dfs(has_appeared, root->left) +
                  "," + dfs(has_appeared, root->right);
    if (has_appeared[node] == 1) {
      res.push_back(root);
    }
    has_appeared[node]++;
    return node;
  }

 public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, int> has_appeared;
    dfs(has_appeared, root);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }