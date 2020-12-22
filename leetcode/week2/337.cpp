#include <bits/stdc++.h>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (memo.find(root) != memo.end())
            return memo.find(root)->second;
        int do_it = root->val
            + (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right))
            + (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
        int no_do = rob(root->left) + rob(root->right);
        return memo[root] =  max(do_it, no_do);;
    }
};
