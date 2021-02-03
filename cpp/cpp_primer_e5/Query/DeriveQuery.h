//
// Created by nigo on 2021/2/3.
//

#ifndef _DERIVEQUERY_H_
#define _DERIVEQUERY_H_

#include <bits/stdc++.h>
#include "Query_base.h"
#include "Query.h"

class WordQuery : Query_base {
  friend class Query;

 protected:
  WordQuery(const std::string &s) : query_word(s) { }
  QueryResult eval(const TextQuery &t) const {
    return t.query(query_word);
  }
  std::string rep () const {
    return query_word;
  }

 private:
  std::string query_word;
};

class NotQuery : public Query_base {
  friend class Query;
  friend Query operator~(const Query&);

 protected:
  NotQuery(const Query &q) : query(q) { }
  std::string rep() const {
    return "~(" + query.rep() + ")";
  }
  QueryResult eval(const TextQuery&) const;
 private:
  Query query;
};

inline Query operator~(const Query &operand) {
//  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

//抽象基类
class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query &l, const Query &r, std::string s) :
  	lhs(l), rhs(r), opSym(s) { }
  std::string rep() const {
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
  }

  Query lhs, rhs;
  std::string opSym;
};

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") { }
  QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
//  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") { }
  QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
//  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif //_DERIVEQUERY_H_