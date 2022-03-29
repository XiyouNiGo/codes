#include <bits/stdc++.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string res;
    int ia = a.size() - 1, ib = b.size() - 1;
    int carry = 0;
    while (ia >= 0 || ib >= 0) {
      int x = ia >= 0 ? a[ia] - '0' : 0;
      int y = ib >= 0 ? b[ib] - '0' : 0;

      int sum = x + y + carry;
      res.push_back('0' + sum % 2);
      carry = sum / 2;
      ia--;
      ib--;
    }
    if (carry != 0) {
      res.push_back('0' + carry);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }