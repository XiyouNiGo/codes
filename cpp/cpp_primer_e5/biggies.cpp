#include <bits/stdc++.h>

using namespace std;

void biggies(vector<string> &words, vector<string>::size_type sz) {
  stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
    return s1.size() < s2.size();
  });
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {
	return a.size() >= sz;
  });
  for_each(wc, words.end(), [](const string &s) {
    cout << s << endl;
  });
}
int main(int argc, char *argv[]) {
    cout << "Hello world" << endl;
    return 0;
}

