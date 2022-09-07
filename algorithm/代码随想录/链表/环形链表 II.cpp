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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    do {
      if (slow == nullptr || fast == nullptr || fast->next == nullptr) {
        return nullptr;
      }
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast);
    while (head != slow) {
      head = head->next;
      slow = slow->next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) { return 0; }