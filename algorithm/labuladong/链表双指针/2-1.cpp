#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode dummy;
    ListNode *head = &dummy, *tail = head;
    while (l1 || l2) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }
    if (carry) {
      tail->next = new ListNode(carry);
      // tail = tail->next;
    }
    return dummy.next;
  }
};

int main(int argc, char* argv[]) { return 0; }