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
  // 解法三： 递归
  // Time: O(N)
  // Space: O(N)
  ListNode *front_head;
  bool recur(ListNode *head) {
    if (head == nullptr) {
      return true;
    }
    if (recur(head->next) == false) {
      return false;
    }
    if (head->val != front_head->val) {
      return false;
    } else {
      assert(front_head);
      front_head = front_head->next;
      return true;
    }
  }

  bool isPalindrome(ListNode *head) {
    front_head = head;
    return recur(head);
  }
};

int main(int argc, char *argv[]) { return 0; }