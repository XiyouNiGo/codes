#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 栈
  int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<int> s;
    for (int i = 0; i < n; i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
          tokens[i] == "/") {
        // 顺序不能乱
        int num2 = s.top();
        s.pop();
        int num1 = s.top();
        s.pop();
        switch (tokens[i][0]) {
          case '+':
            s.push(num1 + num2);
            break;
          case '-':
            s.push(num1 - num2);
            break;
          case '*':
            s.push(num1 * num2);
            break;
          case '/':
            s.push(num1 / num2);
            break;
        }
      } else {
        s.push(atoi(tokens[i].c_str()));
      }
    }
    return s.top();
  }
};

int main(int argc, char* argv[]) { return 0; }