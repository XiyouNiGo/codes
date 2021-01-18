#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;
        //左闭右开区间
        int left, right;
        left = right = 0;
        //已经有效的字符数
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            //移动并更新窗口
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                //字符数量符合要求
                if (window[c] == need[c])
                    valid++;
            }
            //判断左侧窗口是否需要收缩
            while (valid == need.size()) {
                //更新结果
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                //移动并更新窗口
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
