#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // 解法一： BFS
  // O(N) O(N)
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    int layer = 1;
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      list<int> temp;  // 有push_front的需求，所以用list而不是vector
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == nullptr) {
          continue;
        }
        if (layer % 2) {
          temp.push_back(cur->val);
        } else {
          temp.push_front(cur->val);
        }
        q.push(cur->left);
        q.push(cur->right);
      }
      if (temp.size()) {
        res.push_back(vector<int>{temp.begin(), temp.end()});
      }
      layer++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }