#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
      unordered_map<int, bool> umap;
      for (auto num : nums) {
        if (umap[num])
          return num;
          umap[num] = true;
      }
      return -1;
    }
};
    
int main(int argc, char *argv[])
{
    return 0;
}
