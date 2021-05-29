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
    int minDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
      queue<TreeNode*> q;
      q.push(root);
      int depth = 1;
      while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
          TreeNode *front = q.front();
          q.pop();
          if (!front->left && !front->right) {
            return depth;
          }
          if (front->left) {
            q.push(front->left);
          }
          if (front->right) {
            q.push(front->right);
          }
        }
        depth++;
      }
      return depth;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
