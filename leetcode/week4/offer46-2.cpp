#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
      string s = to_string(num);
      int dp_pre = 1, dp = 1;
      for (int i = 2; i <= s.size(); i++) {
        string temp = s.substr(i - 2, 2);
        int old_dp = dp;
        // dp = (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5')) ? dp + dp_pre : dp;
        dp = (temp >= "10" && temp <= "25") ? dp + dp_pre : dp;
        dp_pre = old_dp;
      }
      return dp;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
