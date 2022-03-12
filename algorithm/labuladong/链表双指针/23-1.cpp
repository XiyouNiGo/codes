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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr || l2 == nullptr) {
      return l1 ? l1 : l2;
    }
    ListNode dummy, *p = &dummy;
    ListNode *p1 = l1, *p2 = l2;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy.next;
  }

 public:
  // 解法一： 顺序合并
  // O(k*N^2) O(1)
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }
    ListNode *res = lists[0];
    for (int i = 1; i < lists.size(); i++) {
      res = mergeTwoLists(res, lists[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }