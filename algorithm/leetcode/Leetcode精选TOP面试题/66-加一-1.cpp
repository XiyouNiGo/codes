#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // 解法一： 模拟
  // O(N) O(1)
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
      digits[i] += carry;
      if (i == n - 1) {
        digits[i]++;
      }
      if (digits[i] >= 10) {
        carry = 1;
        digits[i] %= 10;
      } else {
        return digits;
      }
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main(int argc, char* argv[]) { return 0; }