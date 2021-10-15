#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int res = 0;
        unordered_map<char, int> window;
        while (right < s.size()) {
          char c = s[right];
          if (window.count(c)) {
            left = max(left, window[c] + 1);
          }
          window[c] = right;
          res = max(res, right - left + 1);
          right++;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
