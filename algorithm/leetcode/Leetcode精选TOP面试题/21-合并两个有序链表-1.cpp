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
  // 解法一： 迭代
  // O(M + N)
  // O(1)
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* new_head = new ListNode();
    ListNode* p = new_head;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        p->next = list1;
        list1 = list1->next;
      } else {
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    p->next = list1 ? list1 : list2;
    // delete new_head;
    return new_head->next;
  }
};

int main(int argc, char* argv[]) { return 0; }