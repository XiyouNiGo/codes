#include <bits/stdc++.h>

#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
  void plus(char& c) { c = (c == '9' ? '0' : c + 1); }

  void minor(char& c) { c = (c == '0' ? '9' : c - 1); }

 public:
  void test() {
    string s("1234");
    cout << s << endl;
    for (auto& c : s) {
      plus(c);
      cout << s << endl;
      minor(c);

      minor(c);
      cout << s << endl;
      plus(c);
    }
  }
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (visited.count("0000")) {
      return -1;
    }
    int step = 0;
    queue<string> q;
    q.push("0000");
    visited.insert("0000");
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto cur = q.front();
        q.pop();
        if (cur == target) {
          return step;
        }
        for (auto& c : cur) {
          plus(c);
          if (!visited.count(cur)) {
            q.push(cur);
            visited.insert(cur);
          }
          minor(c);

          minor(c);
          if (!visited.count(cur)) {
            q.push(cur);
            visited.insert(cur);
          }
          plus(c);
        }
      }
      step++;
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  Solution().test();
  return 0;
}