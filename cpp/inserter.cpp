#include <bits/stdc++.h>

using namespace std;

void test_inserter() {
  list<int> l1 = {1, 2, 3, 4};
  list<int> l2;
  copy(l1.cbegin(), l1.cend(), front_inserter(l2));

  for_each(l2.begin(), l2.end(), [](int i) {
    cout << i << endl;
  });

  copy(l1.cbegin(), l1.cend(), back_inserter(l2));
  for_each(l2.begin(), l2.end(), [](int i) {
    cout << i << endl;
  });

  auto origin_begin = l2.begin();
  copy(l1.cbegin(), l1.cend(), inserter(l2, origin_begin));
  for_each(l2.begin(), l2.end(), [](int i) {
    cout << i << endl;
  });
}

