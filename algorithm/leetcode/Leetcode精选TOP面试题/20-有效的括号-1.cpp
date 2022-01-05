#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

class Solution {
 public:
  // 解法一： 栈
  bool isValid(string s) {
    int n = s.size();
    if (n % 2) {
      return false;
    }
    unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (pairs.count(s[i])) {
        // 右括号弹出并比较
        if (st.empty() || st.top() != pairs[s[i]]) {
          return false;
        }
        st.pop();
      } else {
        // 左括号直接压入
        st.push(s[i]);
      }
    }
    return st.empty();
  }
};

int main(int argc, char *argv[]) { return 0; }