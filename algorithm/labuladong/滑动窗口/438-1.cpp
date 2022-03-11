#include <bits/stdc++.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for (auto c : p) {
      need[c]++;
    }
    int left = 0, right = 0, valid = 0;
    vector<int> res;
    while (right < s.size()) {
      char c = s[right++];
      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }
      if (right - left == p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
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
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }