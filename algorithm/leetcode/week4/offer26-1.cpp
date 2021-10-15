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
    bool equal(TreeNode *left, TreeNode *right) {
      if (!right) {
        return true;
      }
      if (!left || (left->val != right->val)) {
        return false;
      }
      return equal(left->left, right->left) && equal(left->right, right->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
      stack<TreeNode*> s;
      TreeNode *p = A;
      while (p || !s.empty()) {
        while (p) {
          if (B && p->val == B->val && equal(p, B)) {
            return true;
          }
          s.push(p);
          p = p->left;
        }
        if (!s.empty()) {
          p = s.top()->right;
          s.pop();
        }
      }
      return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}