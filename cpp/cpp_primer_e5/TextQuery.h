#ifndef _TEXTQUERY_H_

#define _TEXTQUERY_H_

#include <bits/stdc++.h>

class QueryResult {
  friend std::ostream &print(std::ostream&, const QueryResult&);

 public:
  using line_no = std::vector<std::string>::size_type;
  QueryResult(std::string s,
			  std::shared_ptr<std::set<line_no>> p,
			  std::shared_ptr<std::vector<std::string>> f) :
			  sought(s), lines(p), file(f) { }

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream&);
  QueryResult query(const std::string&) const;

 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif //_TEXTQUERY_H_
