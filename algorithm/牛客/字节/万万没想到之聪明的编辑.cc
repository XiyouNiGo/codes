#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
  int n = 0;
  cin >> n;
  while (n--) {
    int i = 0;
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      s[i++] = s[j];
      if (i >= 3 && s[i - 3] == s[i - 2] && s[i - 2] == s[i - 1]) {
        i--;
      }
      if (i >= 4 && s[i - 4] == s[i - 3] && s[i - 2] == s[i - 1]) {
        i--;
      }
    }
    s[i] = '\0';
    printf("%s\n", s.c_str());
  }
  return 0;
}