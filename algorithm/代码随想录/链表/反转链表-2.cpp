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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *tail = reverseList(head->next);
    // 1  NULL <- 2 <- 3
    head->next->next = head;
    head->next = nullptr;
    return tail;
  }
};

int main(int argc, char *argv[]) { return 0; }