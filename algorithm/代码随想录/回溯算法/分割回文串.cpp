#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<vector<string>> res;
  vector<string> track;
  void backtrack(const string& s, int start) {
    if (start >= s.size()) {
      res.push_back(track);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        string str = s.substr(start, i - start + 1);
        track.push_back(str);
      } else {
        continue;
      }
      backtrack(s, i + 1);
      track.pop_back();
    }
  }
  bool isPalindrome(const string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

 public:
  vector<vector<string>> partition(string s) {
    backtrack(s, 0);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }