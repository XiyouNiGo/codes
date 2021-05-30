#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode *slow = nullptr, *fast = head;
      while (fast) {
        ListNode *temp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = temp;
      }
      return slow;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
