#include <bits/stdc++.h>

#include <cctype>
#include <numeric>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    int n = s.size();
    vector<int> stk;  // vector来模拟stack
    char pre_op = '+';
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ' && i != n - 1) {
        continue;
      }
      if (isdigit(s[i])) {
        num = num * 10 + static_cast<int>(s[i] - '0');  // 数字可能不止一位
      }
      if (!isdigit(s[i]) || i == n - 1) {
        switch (pre_op) {
          case '+':
            stk.push_back(num);
            break;
          case '-':
            stk.push_back(-num);
            break;
          case '*':
            stk.back() *= num;
            break;
          case '/':
            stk.back() /= num;
            break;
        }
        num = 0;
        pre_op = s[i];
      }
    }
    return accumulate(stk.begin(), stk.end(), 0);
  }
};

int main(int argc, char *argv[]) { return 0; }