#include <bits/stdc++.h>

using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast, *slow;
        fast = slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        delete slow;
        return slow;
    }
};
