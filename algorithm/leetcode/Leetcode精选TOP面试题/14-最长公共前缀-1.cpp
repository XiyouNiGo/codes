#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 纵向扫描
  // O(M * N) O(1)
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return string();
    }
    int n = strs.size();
    int size = strs[0].size();
    for (int i = 0; i < size; i++) {
      char c = strs[0][i];
      for (int j = 1; j < n; j++) {
        if (i == strs[j].size() || strs[j][i] != c) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};

int main(int argc, char* argv[]) { return 0; }