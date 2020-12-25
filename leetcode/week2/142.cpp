#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (!fast || !fast->next)
            return nullptr;
        //设相遇时，slow移动长度为k
        //fast移动为2k
        //易知k为环长整数倍
        //设相遇点与环入口距离为m
        //则相遇点与起点距离为k-m
        //相遇点与环入口距离为k-m
        //故设一指针指向起点
        //再次相遇处为环入口
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
