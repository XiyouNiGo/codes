#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n = 0, op = 0;
  scanf("%d%d \n", &n, &op);
  string s, t;
  getline(cin, s);

  int len = s.size();
  if (op == 2) {
    // decode
    for (int i = 1; i <= len; i++) {
      t.insert(t.begin() + ((i + 1) / 2 - 1), s.back());
      s.pop_back();
    }
  } else {
    // encode
    for (int i = len; i >= 1; i--) {
      t.push_back(s[(i + 1) / 2 - 1]);
      s.erase(s.begin() + ((i + 1) / 2 - 1));
    }
  }
  cout << t;
  return 0;
}