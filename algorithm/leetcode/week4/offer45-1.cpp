#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
      string res;
      vector<string> strs;
      for (auto num : nums) {
        strs.push_back(to_string(num));
      }
      sort(strs.begin(), strs.end(), [](string s1, string s2){
        return (s1 + s2) < (s2 + s1);
      });
      for (auto s : strs) {
        res.append(s);
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
