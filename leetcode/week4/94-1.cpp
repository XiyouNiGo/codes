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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<TreeNode*> s;
      TreeNode *p = root;
      while (p || !s.empty()) {
        while (p) {
          s.push(p);
          p = p->left;
        }
        if (!s.empty()) {
          res.push_back(s.top()->val);
          p = s.top()->right;
          s.pop();
        }
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}