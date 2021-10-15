#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
      if (k <= 0 || head == nullptr) {
        return nullptr;
      }
      ListNode *slow = head, *fast = head;
      while (--k) {
        if (fast) {
          fast = fast->next;
        } else {
          return nullptr;
        }
      }
      while (fast->next) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
