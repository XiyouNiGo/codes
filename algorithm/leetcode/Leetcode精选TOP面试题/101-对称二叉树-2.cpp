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
  // 解法二： 队列
  // O(N) O(N)
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    TreeNode *n1 = nullptr, *n2 = nullptr;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n / 2; i++) {
        n1 = q.front();
        q.pop();
        n2 = q.front();
        q.pop();
        if (n1 == nullptr && n2 == nullptr) {
          continue;
        }
        if (n1 == nullptr || n2 == nullptr) {
          return false;
        }
        if (n1->val != n2->val) {
          return false;
        }
        if (n1 && n2) {
          q.push(n1->left);
          q.push(n2->right);
          q.push(n1->right);
          q.push(n2->left);
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }