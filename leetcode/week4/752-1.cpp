#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      queue<string> q;
      q.push("0000");
      unordered_set<string> visited(deadends.begin(), deadends.end());
      if (visited.count("0000")) {
        return -1;
      }
      visited.insert("0000");
      int step = 0;
      while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; ++i) {
          string front = q.front();
          q.pop();
          if (front == target) {
            return step;
          }
          for (int j = 0; j < 4; j++) {
            for (int k = -1; k <= 1; k += 2) {
              string temp = move(front, j, k);
              if (!visited.count(temp)) {
                q.push(temp);
                visited.insert(temp);
              }
            }
          }
        }
        step++;
      }
      return -1;
    }
private:
    inline string move(string s, int i, int j) {
      s[i] = (s[i] - '0' + j + 10) % 10 + '0';
      return s;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
