#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMax(vector<int>& a, int k, int x) {
    if (a.size() == 0) {
      return 0;
    }
    make_heap(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
      pop_heap(a.begin(), a.end());
      a.back() -= x;
      push_heap(a.begin(), a.end());
    }
    return a[0];
  }
};

int main(int argc, char* argv[]) {
  vector<int> a = {7, 2, 1};
  cout << Solution().minMax(a, 3, 2) << endl;
  return 0;
}