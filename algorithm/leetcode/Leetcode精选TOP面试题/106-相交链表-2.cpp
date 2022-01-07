#include <bits/stdc++.h>

#include <unordered_set>

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
  // 解法二： 双指针
  // O(N + M)
  // O(1)
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    ListNode *pa = headA, *pb = headB;
    // 想象成一个小树枝
    while (pa != pb) {
      // 最多循环M + N次
      pa = pa ? pa->next : headB;
      pb = pb ? pb->next : headA;
    }
    return pa;
  }
};

int main(int argc, char *argv[]) { return 0; }