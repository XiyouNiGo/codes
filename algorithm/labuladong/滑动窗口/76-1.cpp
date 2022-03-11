#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (auto c : t) {
      need[c]++;
    }
    int left = 0, right = 0, valid = 0;
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
      char c = s[right++];
      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }
      while (valid == need.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }
        char d = s[left++];
        if (need.count(d)) {
          if (need[d] == window[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

int main(int argc, char *argv[]) { return 0; }