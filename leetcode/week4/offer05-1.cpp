#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
      int src_size, dst_size;
      src_size = dst_size = s.size();
      for (auto c : s) {
        if (c == ' ')
          dst_size += 2;
      }
      s.resize(dst_size);
      for (int i = src_size - 1, j = dst_size - 1; j >= 0; i--, j--) {
        if (s[i] != ' ')
          s[j] = s[i];
        else {
          s.replace(j - 2, 3, "%20");
          j -= 2;
        }
      }
      return s;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
