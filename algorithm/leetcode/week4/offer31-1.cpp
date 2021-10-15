#include <bits/stdc++.h>

using namespace std;

class Solution {
    stack<int> s;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int i = 0;
      for (auto j : pushed) {
        s.push(j);
        while (!s.empty() && s.top() == popped[i]) {
          s.pop();
          i++;
        }
      }
      return s.empty();
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
