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
  void deleteNode(ListNode *node) {
    // 解法一： 和下一个节点交换
    // O(1)
    // O(1)
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int main(int argc, char *argv[]) { return 0; }