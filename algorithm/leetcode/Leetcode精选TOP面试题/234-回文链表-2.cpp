#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  // 解法二： 双指针（先复制到数组）
  // Time: O(N)
  // Space: O(N)
  bool isPalindrome(ListNode *head) {
    vector<int> nums;
    ListNode *p = head;
    while (p) {
      nums.push_back(p->val);
      p = p->next;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] != nums[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }