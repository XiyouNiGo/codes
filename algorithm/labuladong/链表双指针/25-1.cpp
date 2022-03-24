#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *reverseList(ListNode *head, ListNode *tail) {
    // 左闭右开
    ListNode *cur = head, *pre = nullptr, *temp = nullptr;
    while (cur != tail) {
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }

 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *tail = head;
    for (int i = 0; i < k; i++, tail = tail->next) {
      if (tail == nullptr) {
        return head;
      }
    }
    ListNode *new_head = reverseList(head, tail);
    // 原来的head成了尾节点
    head->next = reverseKGroup(tail, k);
    return new_head;
  }
};

int main(int argc, char *argv[]) { return 0; }