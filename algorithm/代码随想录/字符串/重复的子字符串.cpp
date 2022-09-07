#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    string t = s + s;
    t.erase(t.begin());
    t.erase(t.end() - 1);
    // find: O(M+N)
    if (t.find(s) != std::string::npos) return true;
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }