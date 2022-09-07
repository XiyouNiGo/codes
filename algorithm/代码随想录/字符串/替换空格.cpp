#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Solution {
 public:
  // 扩充数组再从后往前操作
  string replaceSpace(string s) {
    int count = count_if(s.begin(), s.end(),
                         [](char val) -> bool { return val == ' '; });
    int oldSize = s.size();
    s.resize(s.size() + count * 2);
    int newSize = s.size();
    for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
      if (s[j] != ' ') {
        s[i] = s[j];
      } else {
        s[i] = '0';
        s[i - 1] = '2';
        s[i - 2] = '%';
        i -= 2;
      }
    }
    return s;
  }
};

int main(int argc, char *argv[]) { return 0; }