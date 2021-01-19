#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window;
        for (auto c : p) need[c]++;
        int left, right, valid;
        left = right = valid = 0;
        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (right - left > p.size()) {
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
            if (valid == need.size())
                res.push_back(left);
        }
        return res;
    }
};
