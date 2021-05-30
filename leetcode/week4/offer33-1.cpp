#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool partition(vector<int>& postorder, int left, int right) {
      if (left > right) {
        return true;
      }
      int division = left;
      while (postorder[division] < postorder[right]) {
        division++;
      }
      int p = division;
      while (postorder[p] > postorder[right]) {
        p++;
      }
      return p == right && partition(postorder, left, division - 1) && partition(postorder, division, right - 1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
      return partition(postorder, 0, postorder.size() - 1);
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
