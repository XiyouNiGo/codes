#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int helper(TreeNode *root) {
      if (root == nullptr) {
        return 0;
      }
      int left_depth = 0, right_depth = 0;
      if ((left_depth = helper(root->left)) == -1) {
        return -1;
      }
      if ((right_depth = helper(root->right)) == -1) {
        return -1;
      }
      return abs(left_depth - right_depth) <= 1 ? max(left_depth, right_depth) + 1 : -1;
    }
public:
    bool isBalanced(TreeNode* root) {
      return helper(root) != -1;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
