#include <bits/stdc++.h>

using namespace std;

void test_istream_iterator() {
  istream_iterator<int> cin_iter_int(cin);
  istream_iterator<int> eof_int;
  cout << *(cin_iter_int++) << endl;
  while (cin_iter_int != eof_int)
//    cout << unitbuf;
    cout << *(cin_iter_int++) << endl;

  //流迭代器构造vector
  vector<int> vec(cin_iter_int, eof_int);

  cout << accumulate(cin_iter_int, eof_int, 0) << endl;
}
