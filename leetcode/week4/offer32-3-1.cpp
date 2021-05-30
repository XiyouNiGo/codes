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
        int step = 0;
        while (!q.empty()) {
          deque<int> dq;
          int qsize = q.size();
          for (int i = 0; i < qsize; i++) {
            TreeNode *front = q.front();
            q.pop();
            if (step & 1) {
              dq.push_front(front->val);
            } else {
              dq.push_back(front->val);
            }
            if (front->left) {
              q.push(front->left);
            }
            if (front->right) {
              q.push(front->right);
            }
          }
          step++;
          vector<int> r(dq.begin(), dq.end());
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
