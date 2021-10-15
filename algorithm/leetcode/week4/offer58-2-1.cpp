#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
      rotate(s.begin(), s.begin() + n, s.end());
      return s;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
