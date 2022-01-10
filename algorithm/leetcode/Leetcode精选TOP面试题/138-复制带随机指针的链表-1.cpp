#include <bits/stdc++.h>

#include <unordered_map>

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
  // 解法一： 迭代(2) + 哈希表
  // O(N) O(N)
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return head;
    }
    Node dummy(0);
    unordered_map<Node*, Node*> old2new;
    for (Node *p = head, *pd = &dummy; p != nullptr;
         p = p->next, pd = pd->next) {
      pd->next = new Node(p->val);
      old2new[p] = pd->next;
    }
    for (Node *p = head, *pd = dummy.next; pd != nullptr;
         p = p->next, pd = pd->next) {
      auto it = old2new.find(p->random);
      if (it != old2new.end()) {
        pd->random = it->second;
      } else {
        pd->random = nullptr;
      }
    }
    return dummy.next;
  }
};

int main(int argc, char* argv[]) { return 0; }