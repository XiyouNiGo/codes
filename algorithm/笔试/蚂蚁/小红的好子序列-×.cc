#include <bits/stdc++.h>

#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int left = 0, right = 0, count = 0;
  unordered_map<char, int> window;
  while (right < s.size()) {
    char c = s[right++];
    window[c]++;
    if (right - left < 3) {
      continue;
    }
    if (window.size() == 2) {
      count++;
    }
    window[c]--;
    if (window[c] == 0) {
      window.erase(c);
    }
  }
  cout << count;
  return 0;
}