#include <bits/stdc++.h>

using namespace std;

using namespace std::placeholders;  //_1

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void test_bind(vector<string> &words, string::size_type sz) {
    auto wc = find_if(words.begin(), words.end(),
                      bind(check_size, _1, sz));
}

