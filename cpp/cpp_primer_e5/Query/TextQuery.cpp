//
// Created by nigo on 2021/2/3.
//

#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery (ifstream &is) : file(new vector<string>){
  string text;
  while (getline(is, text)) {
	  file->push_back(text);
	  int n = file->size() - 1;
	  istringstream line(text);
	  string word;
	  while (line >> word) {
		  auto &lines = wm[word];
		  if (!lines)
			lines.reset(new set<line_no>);
		  lines->insert(n);
		}
	}
}

QueryResult TextQuery::query (const string &sought) const {
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto loc = wm.find(sought);
  if (loc == wm.end())
	return QueryResult(sought, nodata, file);
  return QueryResult(sought, loc->second, file);
}

std::ostream &print (ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
  for (auto num : *qr.lines) {
	  os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	}
  return os;
}