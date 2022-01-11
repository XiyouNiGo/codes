#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
  // 返回[left, right]之间的最长公共前缀串
  string Recur(vector<string>& strs, int left, int right) {
    if (left == right) {
      return strs[left];
    }
    int mid = left + (right - left) / 2;
    string s1 = Recur(strs, left, mid);
    string s2 = Recur(strs, mid + 1, right);
    int n = min(s1.size(), s2.size());
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        return s1.substr(0, i);
      }
    }
    return s1.substr(0, n);
  }

 public:
  // 解法二： 分治
  // O(M * N) O(M * logN)
  string longestCommonPrefix(vector<string>& strs) {
    return Recur(strs, 0, strs.size() - 1);
  }
};

int main(int argc, char* argv[]) { return 0; }