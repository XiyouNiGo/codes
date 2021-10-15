#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *nodeA = headA, *nodeB = headB;
      while (nodeA != nodeB) {
        nodeA = nodeA ? nodeA->next : headB;
        nodeB = nodeB ? nodeB->next : headA;
      }
      return nodeA;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
