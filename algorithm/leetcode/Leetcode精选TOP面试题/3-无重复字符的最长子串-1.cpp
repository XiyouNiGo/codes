#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

class Solution {
 public:
  // 解法一： 滑动窗口
  // Time: O(N)
  int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> window;
    // [left, right]
    while (right < s.size()) {
      char c = s[right];
      window[c]++;
      right++;
      while (window[c] > 1) {
        window[s[left]]--;
        left++;
      }
      res = max(res, right - left);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }