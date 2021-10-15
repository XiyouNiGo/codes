#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto c : s1) need[c]++;
        int left, right, valid;
        left = right = valid = 0;
        while (right < s2.size()) {
            char c = s2[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (right - left > s1.size()) {
                char d = s2[left++];
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
            if (valid == need.size())
                return true;
        }
        return false;
    }
};
