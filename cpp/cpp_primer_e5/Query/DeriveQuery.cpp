//
// Created by nigo on 2021/2/3.
//

#include "DeriveQuery.h"
#include "QueryResult.h"

using namespace std;

QueryResult OrQuery::eval(const TextQuery &text) const {
  auto right = rhs.eval(text);
  auto left = lhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file);
}

//QueryResult AndQuery::eval(const TextQuery &text) const {
//  auto right = rhs.eval(text);
//  auto left = lhs.eval(text);
//  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
//  ret_lines->insert(right.begin(), right.end());
//  return QueryResult(rep(), ret_lines, left.get_file);
//}

//QueryResult OrQuery::eval(const TextQuery &text) const {
//  auto right = rhs.eval(text);
//  auto left = lhs.eval(text);
//  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
//  ret_lines->insert(right.begin(), right.end());
//  return QueryResult(rep(), ret_lines, left.get_file);
//}