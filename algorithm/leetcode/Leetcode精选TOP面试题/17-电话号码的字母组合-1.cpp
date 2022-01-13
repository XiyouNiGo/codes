#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

class Solution {
  vector<string> res;
  unordered_map<char, string> phone_map = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };

  void backtrace(const string& digits, int index, string& track) {
    if (index >= digits.size()) {
      res.push_back(track);
      return;
    }
    char digit = digits[index];
    for (auto& i : phone_map[digit]) {
      track.push_back(i);
      backtrace(digits, index + 1, track);
      track.pop_back();
    }
  }

 public:
  // 解法一： 回溯
  // O(3^N) O(N)
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return {};
    }
    string track;
    backtrace(digits, 0, track);
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }