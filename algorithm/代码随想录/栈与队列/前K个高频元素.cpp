#include <bits/stdc++.h>

using namespace std;

// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
 public:
  class mycomparison {
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]]++;
    }

    // 小顶堆（默认为大顶堆）
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison>
        prioQueue;

    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end();
         it++) {
      prioQueue.push(*it);
      if (prioQueue.size() > k) {
        prioQueue.pop();
      }
    }

    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--) {
      res[i] = prioQueue.top().first;
      prioQueue.pop();
    }
    return res;
  }
};

int main(int argc, char* argv[]) { return 0; }