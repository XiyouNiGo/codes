#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) {
          ListNode* node = head->next;
          free(node);
          return node;
        }
        ListNode *pre = head, *cur = head->next;
        while(cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if(cur != nullptr) {
          pre->next = cur->next;
          free(cur);
        }
        return head;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}
