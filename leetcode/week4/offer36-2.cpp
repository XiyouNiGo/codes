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
public:
    Node* treeToDoublyList(Node* root) {
      if (root == nullptr) {
        return nullptr;
      }
      Node *head = nullptr, *prev = nullptr;
      stack<Node*> s;
      Node *p = root;
      while (p || !s.empty()) {
        while (p) {
          s.push(p);
          p = p->left;
        }
        if (!s.empty()) {
          Node *top = s.top();
          if (head == nullptr) {
            head = top;
          } else {
            prev->right = top;
          }
          top->left = prev;
          prev = top;
          p = top->right;
          s.pop();
        }
      }
      head->left = prev;
      prev->right = head;
      return head;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
