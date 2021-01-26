#include <bits/stdc++.h>

using namespace std;

using namespace std::placeholders;  //_1

ostream &print(ostream &os, const string &s, char c) {
    return os << s << c;
}

void test_bind_ref(vector<string> &words, string::size_type sz) {
    //bind为值传递
    //wrong:
    //for_each(words.begin(), words.end(), bind(print, cout, _1, 'A'));

    //使用ref/cref返回对象（该对象包含给定的引用）
    for_each(words.begin(), words.end(), bind(print, ref(cout), _1, 'A'));
}

