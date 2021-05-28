#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head)
          return{};
        vector<int> ret;
        ListNode* p = head;
        while (p) {
            ret.insert(ret.begin(), p->val);
            p = p->next;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
