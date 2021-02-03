//
// Created by nigo on 2021/2/3.
//

#ifndef _QUERY_H_
#define _QUERY_H_

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"

//Query类对外提供接口，同时隐藏了Query_base的继承体系
class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
  friend std::ostream &operator<<(std::ostream&, const Query &query);
 public:
  Query(const std::string&);
  Query(std::shared_ptr<Query_base> query);
//  Query(std::shared_ptr<Query_base> query) : q(query) { };
  //多态
  QueryResult eval(const TextQuery &t) const {
    return q->eval(t);
  }

  std::string rep() const {
    return q->rep();
  }

 private:
  std::shared_ptr<Query_base> q;
};

#endif //_QUERY_H_
