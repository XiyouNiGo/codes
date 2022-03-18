#include <bits/stdc++.h>
#include <math.h>

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
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int h1 = 0, h2 = 0;
    TreeNode *p = root;
    while (p) {
      h1++;
      p = p->left;
    }
    p = root;
    while (p) {
      h2++;
      p = p->right;
    }
    if (h1 == h2) {
      return pow(2, h1) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

int main(int argc, char *argv[]) { return 0; }