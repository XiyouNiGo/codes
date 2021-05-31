#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
      string s = to_string(n);
      int i, j;
      for (i = s.size() - 1; i >= 1 && s[i - 1] >= s[i]; i--) {}
      if (i == 0) {
        return -1;
      }
      for (j = s.size() - 1; s[i - 1] >= s[j]; j--) {}
      swap(s[i - 1], s[j]);
      reverse(s.begin() + i, s.end());
      long ret = stol(s);
      return ret > INT_MAX ? -1 : ret;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().nextGreaterElement(2147483486) << endl;
    return 0;
}
