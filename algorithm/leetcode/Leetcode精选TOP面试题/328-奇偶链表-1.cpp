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
  // 解法一： 分离节点后合并
  // O(N)
  // O(1)
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode odd_head, even_head;
    ListNode *p = head, *odd = &odd_head, *even = &even_head;
    while (p) {
      odd->next = p;
      odd = odd->next;
      p = p->next;
      if (p == nullptr) {
        break;
      }
      even->next = p;
      even = even->next;
      p = p->next;
    }
    odd->next = even_head.next;
    even->next = nullptr;
    return odd_head.next;
  }
};

int main(int argc, char *argv[]) { return 0; }