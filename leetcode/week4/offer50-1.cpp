#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
      unordered_map<char, bool> umap;
      vector<char> order;
      for (int i = 0; i < s.size(); ++i) {
        bool traverse = umap.count(s[i]);
        if (traverse == false) {
          order.push_back(s[i]);
        }
        umap[s[i]] = !traverse;
      }
      for (auto c : order) {
        if (umap[c]) {
          return c;
        }
      }
      return ' ';
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
