#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    int size = a.size();
    vector<int> b(size, 1);
    if (size == 0) return b;
    int left = 1, right = 1;
    for (int i = 0; i < size; i++) {
      b[i] *= left;
      left *= a[i];

      b[size - i - 1] *= right;
      right *= a[size - i - 1];
    }
    return b;
  }
};

int main(int argc, char *argv[])
{
    return 0;
}
