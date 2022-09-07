#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeDuplicates(string S) {
    string res;
    for (char s : S) {
      if (res.empty() || res.back() != s) {
        res.push_back(s);
      } else {
        res.pop_back();
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }