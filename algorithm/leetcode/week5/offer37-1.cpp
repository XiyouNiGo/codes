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

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "[]";
    }
    string res = "[";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int qsize = q.size();
      for (int i = 0; i < qsize; i++) {
        TreeNode* front = q.front();
        q.pop();
        if (front) {
          res.append(to_string(front->val));
          q.push(front->left);
          q.push(front->right);
        } else {
          res.append("null");
        }
        if (!q.empty()) {
          res.append(",");
        }
      }
    }
    res.append("]");
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "[]") {
      return NULL;
    }
    queue<TreeNode*> q;
    stringstream iss(data.substr(1, data.length() - 2));
    string str;
    getline(iss, str, ',');
    TreeNode* root = new TreeNode(atoi(str.c_str()));
    q.push(root);
    while (!q.empty()) {
      TreeNode* front = q.front();
      q.pop();
      getline(iss, str, ',');
      if (str != "null") {
        TreeNode* left = new TreeNode(atoi(str.c_str()));
        front->left = left;
        q.push(left);
      }
      getline(iss, str, ',');
      if (str != "null") {
        TreeNode* right = new TreeNode(atoi(str.c_str()));
        front->right = right;
        q.push(right);
      }
    }
    return root;
  }
};

int main(int argc, char *argv[])
{
    Codec().deserialize("[1,2,3,null,null,4,5]");
    return 0;
}
