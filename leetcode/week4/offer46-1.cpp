#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
      string s = to_string(num);
      vector<int> dp(s.size() + 1);
      dp[0] = dp[1] = 1;
      for (int i = 2; i <= s.size(); i++) {
        string temp = s.substr(i - 2, i);
        dp[i] = (temp >= "10" && temp <= "25") ? dp[i - 1] + dp[i - 2] : dp[i - 1];
      }
      return dp[s.size()];
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
