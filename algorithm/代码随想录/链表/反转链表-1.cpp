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
    ListNode *slow = nullptr, *fast = head;
    while (fast) {
      ListNode *tmp = fast->next;
      fast->next = slow;
      slow = fast;
      fast = tmp;
    }
    return slow;
  }
};

int main(int argc, char *argv[]) { return 0; }