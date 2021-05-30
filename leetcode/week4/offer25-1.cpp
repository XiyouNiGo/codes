#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode node(0);
      node.next = nullptr;
      ListNode *head, *tail;
      head = tail = &node;
      while (l1 && l2) {
        if (l1->val <= l2->val) {
          tail->next = l1;
          l1 = l1->next;
        } else {
          tail->next = l2;
          l2 = l2->next;
        }
        tail = tail->next;
      }
      tail->next = l1 ? l1 : l2;
      return head->next;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
