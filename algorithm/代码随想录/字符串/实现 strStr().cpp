#include <bits/stdc++.h>

using namespace std;

class Solution {
  void getNext(int* next, const string& s) {
    /// i:后缀末尾、next数组下标
    /// j：前缀末尾
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); i++) {
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];  // 回退
      }
      if (s[i] == s[j]) {
        j++;
      }
      next[i] = j;
    }
  }

 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == needle.size()) {
        return (i - needle.size() + 1);
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) { return 0; }