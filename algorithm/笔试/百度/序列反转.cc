#include <bits/stdc++.h>

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

bool check(const string &s) {
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] > s[i + 1]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < Q; i++) {
    string s;
    cin >> s;
    queue<string> q;
    q.push(s);
    unordered_set<string> visited;
    visited.insert(s);
    int step = 0;
    while (!q.empty()) {
      int n = q.size();
      for (int j = 0; j < n; j++) {
        auto front = q.front();
        q.pop();
        if (visited.count(front)) {
          continue;
        }
        visited.insert(front);
        if (check(front)) {
          cout << step;
          return 0;
        }
        for (int k = 1; k < N; k++) {
          string t = front;
          reverse(t.begin(), t.begin() + k + 1);
          q.push(t);
        }
      }
      step++;
    }
  }
  return 0;
}