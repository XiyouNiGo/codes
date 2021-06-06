#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      istringstream iss(s);
      string res, temp;
      while (getline(iss, temp, ' ')) {
        if (!temp.empty()) {
          res = temp + " " + res;
        }
      }
      res.pop_back();
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
