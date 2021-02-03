//
// Created by nigo on 2021/2/3.
//

#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include <bits/stdc++.h>
#include "QueryResult.h"

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
