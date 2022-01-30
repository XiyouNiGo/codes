#ifndef HELLO_MOCK_H_
#define HELLO_MOCK_H_

#include <gmock/gmock.h>

#include <string>

#include "hello.h"

namespace seamless {

class HelloMock : public Hello {
 public:
  MOCK_METHOD0(GetHelloMsg, std::string());
};

}  // namespace seamless

#endif  // HELLO_MOCK_H_