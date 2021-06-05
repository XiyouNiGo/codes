#include <bits/stdc++.h>

using namespace std;

class Solution {
    int sum = 0;
    int helper(int n) {
      sum += n;
      return n > 1 && helper(n-1);
    }
public:
    int sumNums(int n) {
      helper(n);
      return sum;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().sumNums(2) << endl;
    return 0;
}
