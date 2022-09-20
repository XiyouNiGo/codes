#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  // x*y + k(x + y) + k^2
  // 奇数 + 奇数
  // 偶数 + 偶数
  int count = 0;
  int n, k;
  cin >> n >> k;
  vector<int> nums(n), ji, ou;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (nums[i] % 2) {
      ji.push_back(nums[i]);
    } else {
      ou.push_back(nums[i]);
    }
  }
  if (ji.size() >= ou.size()) {
    cout << ou.size() << endl;
    while (ou.size()) {
      cout << ji.back() << " " << ou.back() << endl;
      ji.pop_back();
      ou.pop_back();
    }
  } else {
    cout << (ji.size() + (ou.size() - ji.size()) / 2) << endl;
    while (ji.size()) {
      cout << ji.back() << " " << ou.back() << endl;
      ji.pop_back();
      ou.pop_back();
    }
    while (ou.size() >= 2) {
      cout << ou.back() << " ";
      ou.pop_back();
      cout << ou.back() << endl;
      ou.pop_back();
    }
  }

  return 0;
}