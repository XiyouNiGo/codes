/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-10 18:01:21
 * @LastEditTime: 2021-10-12 10:24:43
 * @Description: file content
 * @FilePath: /leetcode/week6/969-1.cpp
 */
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    recur(arr, arr.size());
    return res;
  }

 private:
  vector<int> res;
  void recur(vector<int>& arr, int end) {
    // [0, end]
    if (end <= 1) {
      return;
    }
    auto max_elem = max_element(arr.begin(), arr.begin() + end);
    reverse(arr.begin(), max_elem + 1);
    res.push_back(distance(arr.begin(), max_elem) + 1);
    reverse(arr.begin(), arr.begin() + end);
    res.push_back(end);
    recur(arr, end - 1);
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr{3, 2, 4, 1};
  for (auto i : Solution().pancakeSort(arr)) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}