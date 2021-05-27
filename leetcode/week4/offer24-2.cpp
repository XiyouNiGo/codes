#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head || head->next)
            return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

