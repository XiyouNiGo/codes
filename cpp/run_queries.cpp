#include <bits/stdc++.h>
#include "TextQuery.h"

using namespace std;

void run_queries(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "Enter the word to look for, or q to quit:";
    string s;
    if (!(cin >> s) || s== "s")
      break;
    print(cout, tq.query(s)) << endl;
  }
}

int main(int argc, char *argv[]) {
  ifstream infile("/home/nigo/桌面/try.cpp");
  run_queries(infile);
  return 0;
}
