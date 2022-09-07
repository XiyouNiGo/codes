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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0, head), *slow = &dummy, *fast = head;
    while (n > 0) {
      fast = fast->next;
      n--;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    return dummy.next;
  }
};

int main(int argc, char *argv[]) { return 0; }