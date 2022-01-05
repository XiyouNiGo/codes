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
  // 模拟
  // Time: O(max(m, n))
  // Space: O(1)
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    assert(l1 && l2);
    int carry = 0;
    ListNode* head = nullptr;  // the head of answer
    ListNode* tail = nullptr;
    while (l1 || l2) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      // append to the answer
      if (head) {
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      } else {
        head = tail = new ListNode(sum % 10);
      }
      // update carry
      carry = sum / 10;
      // traverse
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    if (carry > 0) {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};

int main(int argc, char* argv[]) { return 0; }