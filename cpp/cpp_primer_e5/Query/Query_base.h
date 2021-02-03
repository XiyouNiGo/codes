//
// Created by nigo on 2021/2/3.
//

#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_

#include <bits/stdc++.h>
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"

//抽象基类
class Query_base {
  friend class Query;

 protected:
  using line_no = std::string::size_type;
  //虚构函数隐式的在派生类中使用
  virtual ~Query_base() = default;

 private:
  //返回匹配的QueryResult
  virtual QueryResult eval(const TextQuery&) const = 0;
  virtual std::string rep() const = 0;
};

#endif //_QUERY_BASE_H_
