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
    void backtrack(TreeNode* root, int target, vector<int> &track, int sum) {
      if (root) {
        track.push_back(root->val);
        if (sum + root->val == target && !root->left && !root->right) {
          res.push_back(track);
        }
        backtrack(root->left, target, track, sum + root->val);
        backtrack(root->right, target, track, sum + root->val);
        track.pop_back();
      }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
      vector<int> track;
      backtrack(root, target, track, 0);
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
