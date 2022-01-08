#ifndef SORT_TEST_H_
#define SORT_TEST_H_

#include <gtest/gtest.h>

class SortTestCase : public testing::Test {
 protected:
  std::vector<int> nums = {4, 1, 3, 5, 2, 6};

  static std::vector<int> result;

  virtual void SetUp() {}

  virtual void TearDown() { AssertResult(); }

  void AssertResult() { ASSERT_EQ(nums, result); }
};

#endif  // !SORT_TEST_H_