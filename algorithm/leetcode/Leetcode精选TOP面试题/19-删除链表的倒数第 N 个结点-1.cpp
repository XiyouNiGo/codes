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
  // 解法一： 双指针
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(
        0, head);  // 假目标（因为我们要删除倒数第N个结点，而不是找到）
    ListNode *fast = head, *slow = dummy;
    while (n--) {
      assert(fast);
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    // delete slow->next;
    slow->next = slow->next->next;
    // delete dummy;
    return dummy->next;
  }
};

int main(int argc, char* argv[]) { return 0; }