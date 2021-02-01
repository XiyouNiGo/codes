#include <bits/stdc++.h>

using namespace std;

map<string, string> build_map(ifstream &map_file) {
  map<string, string> trans_map;
  string key;
  string value;
  //getline读取整行，包括前导空格
  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1)
      trans_map[key] = value.substr(1);
    else
      throw runtime_error("no rule for " + key);
  }
  return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
  auto trans_map = build_map(map_file);
  istream_iterator<string> in_iter_s(input);
  istream_iterator<string> eof_s;
  vector<string> vec_s(in_iter_s, eof_s);
  for_each(vec_s.begin(), vec_s.end(), [&](string &s) {
    if (trans_map.count(s))
      cout << trans_map[s] << endl;
    else
      cout << s << endl;
  });
}

int main(int argc, char *argv[]) {
    cout << "Hello world" << endl;
    return 0;
}

