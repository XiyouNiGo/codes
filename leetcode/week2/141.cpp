#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//哈希表
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> seen;
        while (head) {
            if (seen.count(head))
                return true;
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};*/
//快慢指针
class Solution {
public:
    /*
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head->next, *slow = head;
        while (fast != slow) {
            //快指针在前面跑
            //因此无需判断慢指针
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }*/
    //fast和slow同起点
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
