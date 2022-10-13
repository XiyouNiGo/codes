#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isGoodNumber(int n) {
  string s = to_string(n);
  unordered_set<int> uset;
  for (auto c : s) {
    if (uset.count(c)) {
      return false;;
    }
    uset.insert(c);
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int t1 = 99999, t = 0;
  for (int i = 0; i < n; i++) {
    while (!isGoodNumber(t1)) {
      t1--;
    }
    t = t1;
    t1--;
  }
  string res = to_string(t);
  reverse(res.begin(), res.end());
  while (res.size() != 5) {
    res.push_back('0');
  }
  reverse(res.begin(), res.end());
  cout << res;
  return 0;
}