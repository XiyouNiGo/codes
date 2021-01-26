#include <bits/stdc++.h>

using namespace std;

void test_ostream_iterator() {
  ostream_iterator<int> cout_iter_int(cout, " ");
  vector<int> vec;
  vec.resize(10);
  fill_n(vec.begin(), vec.size(), 0);
  copy(vec.begin(), vec.end(), cout_iter_int);
  cout << endl;
  int temp = 1;
  transform(vec.begin(), vec.end(), vec.begin(), [&](int i)->int {
    return i + temp++;
  });
  copy(vec.begin(), vec.end(), cout_iter_int);
  cout << endl;
}
