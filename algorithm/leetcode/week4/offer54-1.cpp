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
    int kthLargest(TreeNode* root, int k) {
      stack<TreeNode*> s;
      TreeNode *p = root;
      vector<int> inorder;
      while (p || !s.empty()) {
        while (p) {
          s.push(p);
          p = p->right;
        }
        if (!s.empty()) {
          if (--k == 0) {
            return s.top()->val;
          }
          p = s.top()->left;
          s.pop();
        }
      }
      return -1;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
