#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      auto range = equal_range(nums.begin(), nums.end(), target);
      return range.second - range.first;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
