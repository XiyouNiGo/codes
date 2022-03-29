#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int N, K;
  cin >> N >> K;
  vector<int> nums;
  for (int i = 1; i <= K; i++) {
    int n = i * N, m = 0;
    while (n) {
      m *= 10;
      m += n % 10 ;
      n /= 10;
    }
    nums.push_back(m);
  }
  // for (int i = 0; i < nums.size(); i++) {
  //   cout << nums[i] << " ";
  // }
  // cout << endl;
  cout << *max_element(nums.begin(), nums.end());
  return 0;
}