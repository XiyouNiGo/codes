#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
      long digit = 1, start = 1, count = 9;
      while (n > count) {
        n -= count;
        digit++;
        start *= 10;
        count = digit * start * 9;
      }
      long num = start + (n - 1) / digit;
      return to_string(num)[(n - 1) % digit] - '0';
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
