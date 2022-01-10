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
  // 解法一： 自顶向下归并排序
  // O(N * logN) O(logN)
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // 分割
    ListNode* tmp = slow->next;
    slow->next = nullptr;
    ListNode dummy, *p = &dummy;
    ListNode *left = sortList(head), *right = sortList(tmp);
    while (left && right) {
      if (left->val < right->val) {
        p->next = left;
        left = left->next;
      } else {
        p->next = right;
        right = right->next;
      }
      p = p->next;
    }
    p->next = left ? left : right;
    return dummy.next;
  }
};

int main(int argc, char* argv[]) { return 0; }