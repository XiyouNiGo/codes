#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
      int i = 0, sign = 1;
      long res = 0;
      for (i = 0; i < str.size() && str[i] == ' '; i++);
      if (i == str.size()) return 0;
      if (str[i] == '-') {
        i++;
        sign = -1;
      } else if (str[i] == '+') {
        i++;
      }
      for (int j = i; j < str.size(); j++) {
        if (!isdigit(str[j])) break;
        res = res * 10 + str[j] - '0';
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;
      }
      return sign * res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
