#include "gtest/gtest.h"

TEST(Gtest, Hello) {
  ASSERT_TRUE(false) << "Hello Gtest" << std::endl;
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
