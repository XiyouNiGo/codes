#include <bits/stdc++.h>

using namespace std;

class Node {
public:
   int val;
   Node* next;
   Node* random;

   Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (!head) {
        return nullptr;
      }
      Node *p = head;
      while (p) {
        Node *temp = new Node(p->val);
        temp->next = p->next;
        p->next = temp;
        p = temp->next;
      }
      p = head;
      while (p) {
        p->next->random = !p->random ? nullptr : p->random->next;
        p = p->next->next;
      }
      p = head->next;
      while (p->next) { 
        Node *temp = p->next->next;
        p = p->next = temp;
      }
      return head->next;
    }
};

int main(int argc, char *argv[])
{
    Node *node = new Node(5);
    node->next = new Node(6);
    Node *p = Solution().copyRandomList(node);
    while (p) {
      cout << p->val << endl;
      p = p->next;
    }
    if (p == node) {
      cout << "hhh" << endl;
    }
    return 0;
}
