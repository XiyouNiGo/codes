#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string s, path;
int cnt = 0;

void traverse(int start) {
  if (path.size() == 3) {
    string t = path;
    sort(t.begin(), t.end());
    if ((t[0] == t[1] && t[0] != t[2]) || (t[1] == t[2] && t[0] != t[1])) {
      cnt++;
      cout << path << endl;
    }
    return;
  }
  if (start >= s.size()) {
    return;
  }
  for (int i = start; i < s.size(); i++) {
    path.push_back(s[i]);
    traverse(i + 1);
    path.pop_back();
  }
}

int main(int argc, char *argv[]) {
  cin >> s;
  traverse(0);
  cout << cnt;
  return 0;
}