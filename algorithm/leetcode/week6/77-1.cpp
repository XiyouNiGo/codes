#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) {
      return {};
    }
    res.resize(factorial(n - k, n) / factorial(1, k));
    cout << res.capacity() << endl;
    res.resize(0);
    backtrack(n, k, 1);
    return res;
  }

 private:
  vector<int> track;
  vector<vector<int>> res;
  size_t factorial(size_t m, size_t n) {
    size_t ret = 1;
    for (size_t i = m; i <= n; i++) {
      ret *= i;
    }
    return ret;
  }
  void backtrack(int n, int k, int start) {
    if (track.size() == k) {
      res.push_back(track);
    }
    for (int i = start; i <= n; ++i) {
      track.push_back(i);
      backtrack(n, k, i + 1);
      track.pop_back();
    }
  }
};

int main(int argc, char* argv[]) {
  Solution().combine(4, 2);
  return 0;
}