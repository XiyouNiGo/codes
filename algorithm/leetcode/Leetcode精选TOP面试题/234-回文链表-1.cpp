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
  // 解法一： 栈
  // Time: O(N)
  // Space: O(N)
  bool isPalindrome(ListNode *head) {
    stack<int> s;
    ListNode *p = head;
    while (p) {
      s.push(p->val);
      p = p->next;
    }
    while (head) {
      if (head->val != s.top()) {
        return false;
      }
      s.pop();
      head = head->next;
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }