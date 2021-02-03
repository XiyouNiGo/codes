//
// Created by nigo on 2021/2/3.
//

#include "Query.h"

std::ostream &operator<<(std::ostream &os, const Query &query) {
  return os << query.rep();
}