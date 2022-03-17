#include <bits/stdc++.h>

using namespace std;

class Solution {
  bool valid(const string& str) {
    int balance = 0;
    for (char c : str) {
      if (c == '(') {
        ++balance;
      } else {
        --balance;
      }
      if (balance < 0) {
        return false;
      }
    }
    return balance == 0;
  }

  void generate_all(string& current, int n, vector<string>& result) {
    if (n == current.size()) {
      if (valid(current)) {
        result.push_back(current);
      }
      return;
    }
    current += '(';
    generate_all(current, n, result);
    current.pop_back();
    current += ')';
    generate_all(current, n, result);
    current.pop_back();
  }

 public:
  // 解法一： 回溯
  // O（2^2n * N) O(N)
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generate_all(current, n * 2, result);
    return result;
  }
};

int main(int argc, char* argv[]) { return 0; }