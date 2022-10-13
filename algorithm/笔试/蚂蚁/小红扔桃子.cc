#include <bits/stdc++.h>

#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n, x, y;
  cin >> n;
  unordered_map<int, int> row, col;
  while (n--) {
    cin >> x >> y;
    row[x]++;
    col[y]++;
  }
  cout << "----" << endl;
  for (auto &elem : row) {
    cout << elem.first << " " << elem.second << endl;
  }
  for (auto &elem : col) {
    cout << elem.first << " " << elem.second << endl;
  }
  // int count = 0;

  // cout << count;
  return 0;
}