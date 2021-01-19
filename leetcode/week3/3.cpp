#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left, right, res;
        left = right = res = 0;
        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            while (window[c] != 1) {
                char d = s[left++];
                window[d]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
