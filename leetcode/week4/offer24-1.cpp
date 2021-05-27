#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL, *post = head, *temp;
        while (post) {
            temp = post->next;
            post->next = cur;
            cur = post;
            post = temp;
        }
        return cur;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

