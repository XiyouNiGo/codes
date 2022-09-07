#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int slow = 0, fast = 0;
    while (fast < s.size() && s[fast] == ' ') {
      fast++;
    }
    for (; fast < s.size(); fast++) {
      if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') {
        continue;
      } else {
        s[slow++] = s[fast];
      }
    }
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }
    reverse(s.begin(), s.end());
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
        start = i + 1;
      }
    }
    return s;
  }
};

int main(int argc, char *argv[]) { return 0; }