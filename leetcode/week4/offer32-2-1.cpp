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
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
          vector<int> r;
          int qsize = q.size();
          for (int i = 0; i < qsize; i++) {
            TreeNode *front = q.front();
            q.pop();
            r.push_back(front->val);
            if (front->left) {
              q.push(front->left);
            }
            if (front->right) {
              q.push(front->right);
            }
          }
          res.push_back(r);
        }
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
