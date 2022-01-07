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
  // 解法一： 哈希表
  // O(N + M)
  // O(N)
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> visited;
    ListNode *p = headA;
    while (p) {
      visited.insert(p);
      p = p->next;
    }
    p = headB;
    while (p) {
      if (visited.count(p)) {
        return p;
      }
      p = p->next;
    }
    return nullptr;
  }
};

int main(int argc, char *argv[]) { return 0; }