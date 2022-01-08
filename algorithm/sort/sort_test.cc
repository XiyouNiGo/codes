#include "sort_test.h"

#include "sort/bubble_sort.h"
#include "sort/insert_sort.h"
#include "sort/select_sort.h"
#include "sort/shell_sort.h"

using namespace std;

vector<int> SortTestCase::result = {1, 2, 3, 4, 5, 6};

TEST_F(SortTestCase, BubbleSortTest) {
  BubbleSort(nums);
  AssertResult();
}

TEST_F(SortTestCase, SelectSortTest) {
  SelectSort(nums);
  AssertResult();
}

TEST_F(SortTestCase, InsertSortTest) {
  InsertSort(nums);
  AssertResult();
}

TEST_F(SortTestCase, ShellSortTest) {
  ShellSort(nums);
  AssertResult();
}