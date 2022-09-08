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
 private:
  void traversal(TreeNode *cur, string path, vector<string> &res) {
    // 需要遍历根节点的DFS需要在最外面push当前节点
    path += to_string(cur->val);
    if (cur->left == NULL && cur->right == NULL) {
      res.push_back(path);
      return;
    }
    if (cur->left) traversal(cur->left, path + "->", res);
    if (cur->right) traversal(cur->right, path + "->", res);
  }

 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    string path;
    if (root == NULL) return res;
    traversal(root, path, res);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }