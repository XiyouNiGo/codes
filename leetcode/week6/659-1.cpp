/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-10 12:12:01
 * @LastEditTime: 2021-10-10 12:30:47
 * @Description: file content
 * @FilePath: /leetcode/week6/659-1.cpp
 */
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> freq, need;
    for (auto num : nums) {
      freq[num]++;
    }
    for (auto num : nums) {
      if (freq[num] == 0) {
        continue;
      }
      // 优先接到其他子序列后面
      // operator[]：不存在则创建，但对此处无影响
      if (need[num] > 0) {
        freq[num]--;
        need[num]--;
        need[num + 1]++;
      } else if (freq[num] > 0 && freq[num + 1] > 0 && freq[num + 2] > 0) {
        // num可以作为开头
        freq[num]--;
        freq[num + 1]--;
        freq[num + 2]--;
        need[num + 3]++;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  // unordered_map<int, int> map;
  // cout << map.count(1) << endl;
  // cout << map[1] << endl;
  // cout << map.count(1) << endl;
  // cout << map[1] << endl;
  return 0;
}