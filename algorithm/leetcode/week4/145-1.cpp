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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<TreeNode*> s;
      TreeNode *p = root, *q = nullptr;
      while (p || !s.empty()) {
        if (p) {
          s.push(p);
          p = p->left;
        } else {
          p = s.top();
          if (p->right && p->right != q) {
            p = p->right;
          } else {
            s.pop();
            res.push_back(p->val);
            q = p;
            p = nullptr;
          }
        }
      }
      return res;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}
