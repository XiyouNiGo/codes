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
    vector<int> res;
public:
    vector<int> levelOrder(TreeNode* root) {
      if (root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
          int qsize = q.size();
          for (int i = 0; i < qsize; i++) {
            TreeNode *front = q.front();
            q.pop();
            res.push_back(front->val);
            if (front->left) {
              q.push(front->left);
            }
            if (front->right) {
              q.push(front->right);
            }
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
