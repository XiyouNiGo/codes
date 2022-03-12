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

  ListNode *merge(vector<ListNode *> &lists, int left, int right) {
    if (left == right) {
      return lists[left];
    }
    int mid = left + (right - left) / 2;
    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
  }

 public:
  // 解法二： 分治合并
  // O(k*N*logK) O(logK)
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }
    return merge(lists, 0, lists.size() - 1);
  }
};

int main(int argc, char *argv[]) { return 0; }