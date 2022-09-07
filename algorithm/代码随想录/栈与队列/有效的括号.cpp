#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
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
        if (st.empty() || st.top() != pairs[s[i]]) {
          return false;
        }
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    return st.empty();
  }
};

int main(int argc, char *argv[]) { return 0; }