#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> trace;
  vector<vector<int>> res;
  void backtrace(int n, int k, int start) {
    if (n == 0 && k == 0) {
      res.push_back(trace);
      return;
    }
    for (int i = start; i <= 9; i++) {
      trace.push_back(i);
      backtrace(n - i, k - 1, i + 1);
      trace.pop_back();
    }
  }

 public:
  // 和为n，k个数
 vector<vector<int>> combinationSum3(int k, int n) {
   backtrace(n, k, 1);
   return res;
    }
};

int main(int argc, char *argv[]) {
  return 0;
}