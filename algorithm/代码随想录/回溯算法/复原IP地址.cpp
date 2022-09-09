#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<string> res;
  void backtrack(string& s, int start, int n) {
    if (n == 3) {
      if (isValid(s, start, s.size() - 1)) {
        res.push_back(s);
      }
      return;
    }
    for (int i = start; i < s.size(); i++) {
      if (isValid(s, start, i)) {
        s.insert(s.begin() + i + 1, '.');
        backtrack(s, i + 2, n + 1);
        s.erase(s.begin() + i + 1);
      } else
        break;
    }
  }
  bool isValid(const string& s, int start, int end) {
    if (start > end) {
      return false;
    }
    if (s[start] == '0' && start != end) {
      return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
      if (s[i] > '9' || s[i] < '0') {
        return false;
      }
      num = num * 10 + (s[i] - '0');
      if (num > 255) {
        return false;
      }
    }
    return true;
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    res.clear();
    if (s.size() < 4 || s.size() > 12) return res;
    backtrack(s, 0, 0);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }