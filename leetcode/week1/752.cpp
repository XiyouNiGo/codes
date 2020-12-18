#include <bits/stdc++.h>

using namespace std;

string plusOne(string s, int i) {
    if (s[i] == '9') s[i] = '0';
    else s[i] += 1;
    return s;
}

string minusOne(string s, int i) {
    if (s[i] == '0') s[i] = '9';
    else s[i] -= 1;
    return s;
}

int openLock(vector<string>& deadends, string target) {
    queue<string> q;
    //小技巧：直接认为deadends中元素访问过
    set<string> visited(deadends.begin(), deadends.end());
    visited.insert("0000");
    q.push("0000");
    int step = 0;
    while (!q.empty()) {
        //出队判断并扩散节点
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            if (cur == target) {
                return step;
            }
            for (int j = 0; j < 4; j++) {
                string p = plusOne(cur, j);
                if (visited.find(p) == visited.end()) {
                    q.push(p);
                    visited.insert(p);
                }
                string m = minusOne(cur, j);
                if (visited.find(m) == visited.end()) {
                    q.push(m);
                    visited.insert(m);
                }
            }
        }
        step++;
    }
}
