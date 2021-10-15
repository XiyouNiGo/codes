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
public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
