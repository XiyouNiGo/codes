#ifndef HELLO_H_
#define HELLO_H_

#include <string>

namespace seamless {

class Hello {
 public:
  virtual ~Hello() {}

 public:
  virtual std::string GetHelloMsg() = 0;
};

}  // namespace seamless

#endif  // HELLO_H_