#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (st.empty() || st.top() != s[i]) {
        st.push(s[i]);
      } else {
        st.pop();
      }
    }
    string res;
    res.reserve(st.size());
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }