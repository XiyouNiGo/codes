#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> st;
    vector<int> res(T.size(), 0);
    for (int i = 0; i < T.size(); i++) {
      while (!st.empty() && T[i] > T[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }