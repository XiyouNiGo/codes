#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int len = 0;
    while (right < s.size()) {
      char c = s[right++];
      window[c]++;
      while (window[s[left]] > 1) {
        window[s[left]]--;
        left++;
      }
      len = max(len, right - left);
    }
    return len;
  }
};

int main(int argc, char *argv[]) { return 0; }