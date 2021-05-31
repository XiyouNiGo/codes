#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node *prev = nullptr;
    Node *head = nullptr;
    void inorder(Node *root) {
      if (root) {
        inorder(root->left);
        if (head == nullptr) {
          head = root;
        } else {
          prev->right = root;
        }
        root->left = prev;
        prev = root;
        inorder(root->right);
      }
    }
public:
    Node* treeToDoublyList(Node* root) {
      if (root == nullptr) {
        return nullptr;
      }
      inorder(root);
      head->left = prev;
      prev->right = head;
      return head;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
