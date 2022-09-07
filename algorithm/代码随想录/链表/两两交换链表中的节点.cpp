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
 public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *nextHead = swapPairs(head->next->next);
    ListNode *newHead = head->next;
    head->next->next = head;
    head->next = nextHead;
    return newHead;
  }
};

int main(int argc, char *argv[]) { return 0; }