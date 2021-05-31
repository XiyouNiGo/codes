#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      if (k <= 0) {
        return {};
      }
      priority_queue<int, vector<int>> pq(arr.begin(), arr.begin() + k);
      for_each(arr.begin() + k, arr.end(), [&pq](int i){
        if (pq.top() > i) {
          pq.pop();
          pq.push(i);
        }
      });
      vector<int> res;
      while (pq.size()) {
        res.push_back(pq.top());
        pq.pop();
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
