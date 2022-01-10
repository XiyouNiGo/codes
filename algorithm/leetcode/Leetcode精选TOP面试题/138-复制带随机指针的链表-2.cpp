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
  // 解法二： 迭代(3) + 节点拆分
  // O(N) O(1)
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return head;
    }
    for (Node* p = head; p != nullptr; p = p->next->next) {
      Node* q = new Node(p->val);
      q->next = p->next;
      p->next = q;
    }
    for (Node* p = head; p != nullptr; p = p->next->next) {
      p->next->random = p->random ? p->random->next : nullptr;
    }
    Node dummy(0);
    Node* q = &dummy;
    for (Node* p = head; p != nullptr; p = p->next, q = q->next) {
      q->next = p->next;
      p->next = p->next->next;
      // q->next = nullptr;
    }
    q->next = nullptr;
    return dummy.next;
  }
};

int main(int argc, char* argv[]) { return 0; }