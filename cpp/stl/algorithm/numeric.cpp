#include <bits/stdc++.h>

using namespace std;

int main() {
  int ia[5] = {1, 2, 3, 4, 5};
  vector<int> iv(ia, ia + 5);

  cout << accumulate(iv.begin(), iv.end(), 0) << endl;

  cout << accumulate(iv.begin(), iv.end(), 0, minus<int>()) << endl;

  // 内积
  cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;

  cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(),
                        plus<int>())
       << endl;

  ostream_iterator<int> oite(cout, " ");

  partial_sum(iv.begin(), iv.end(), oite);

  partial_sum(iv.begin(), iv.end(), oite, minus<int>());
  cout << endl;

  adjacent_difference(iv.begin(), iv.end(), oite);
  cout << endl;

  adjacent_difference(iv.begin(), iv.end(), oite, plus<int>());
  cout << endl;

  // cout << power(10, 3) << endl;
  // cout << power(10, 3, plus<int>()) << endl;

  int n = 3;
  iota(iv.begin(), iv.end(), n);
  for (int i = 0; i < iv.size(); ++i) cout << iv[i] << ' ';
}
