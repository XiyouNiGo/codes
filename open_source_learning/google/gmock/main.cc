#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "hello_mock.h"

using namespace seamless;
using namespace std;

using ::testing::Return;

int main(int argc, char** argv) {
  // 对未实现的方法进行打桩，实现一个假的依赖类
  // g++ main.cc -lgtest -lgtest_main -lgmock -pthread
  ::testing::InitGoogleMock(&argc, argv);

  string value = "Hello Gmock!";
  HelloMock mock;
  EXPECT_CALL(mock, GetHelloMsg()).Times(1).WillOnce(Return(value));
  cout << "Returned Value: " << mock.GetHelloMsg() << endl;

  return EXIT_SUCCESS;
}
