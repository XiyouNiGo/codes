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
  // 解法一： 插入排序
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode dummy = ListNode(0, head);  // 方便在head位置插入节点
    ListNode* cur = head->next;
    ListNode* last_sorted = head;  // 提高判断效率
    while (cur) {
      if (last_sorted->val <= cur->val) {
        last_sorted = last_sorted->next;
      } else {
        // 否则从dummy开始挨个判断
        ListNode* p = &dummy;
        while (p->next->val <= cur->val) {
          p = p->next;
        }
        last_sorted->next = cur->next;
        cur->next = p->next;
        p->next = cur;
      }
      cur = last_sorted->next;
    }
    return dummy.next;
  }
};

int main(int argc, char* argv[]) { return 0; }