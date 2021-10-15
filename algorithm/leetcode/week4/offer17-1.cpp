#include <bits/stdc++.h>

using namespace std;
// 题目已修改
class Solution {
public:
    void printNumbers(int n) {
      string num;
      backtrack(num, n);
    }
private:
    void backtrack(string &num, int n) {
      if (num.size() > n) {
        return;
      }
      if (!num.empty()) {
        cout << num << endl;
      }
      for (int i = 0; i < 10; ++i) {
        num.append(1, '0' + i);
        backtrack(num, n);
        num.erase(num.end() - 1, num.end());
      }
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    solution.printNumbers(1);
    return 0;
}