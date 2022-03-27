#include <bits/stdc++.h>

#include <cstdlib>
#include <vector>

using namespace std;

void backtrack(vector<int> &nums, int n, int index, int next_odd,
               int next_even) {
  if (index == n) {
    if ((n % 2 && next_odd - 2 == n && next_even - 1 == n) ||
        (n % 2 == 0 && next_odd - 1 == n && next_even - 2 == n)) {
      cout << nums[0];
      for (int i = 1; i < n; i++) {
        cout << " " << nums[i];
      }
      exit(0);
    }
    return;
  }

  // cout << index << " " << next_odd << " " << next_even << endl;

  if ((index == 0) || (nums[(index - 1) / 2] % 2 == 0)) {
    // even
    nums[index] = next_odd;
    backtrack(nums, n, index + 1, next_odd + 2, next_even);
    nums[index] = next_even;
    backtrack(nums, n, index + 1, next_odd, next_even + 2);
  } else {
    // odd
    nums[index] = next_even;
    backtrack(nums, n, index + 1, next_odd, next_even + 2);
  }
}

int main(int argc, char *argv[]) {
  // 奇*奇=奇 奇*偶=偶 偶*偶=偶
  int n;
  cin >> n;
  vector<int> nums(n);
  backtrack(nums, n, 0, 1, 2);
  return 0;
}