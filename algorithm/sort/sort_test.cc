#include "sort_test.h"

#include <algorithm>

#include "sort/bubble_sort.h"
#include "sort/bucket_sort.h"
#include "sort/insert_sort.h"
#include "sort/merge_sort.h"
#include "sort/quick_sort.h"
#include "sort/select_sort.h"
#include "sort/shell_sort.h"

using namespace std;

vector<int> SortTestCase::result = {1, 2, 3, 4, 5, 6};

TEST_F(SortTestCase, BubbleSortTest) { BubbleSort(nums); }

TEST_F(SortTestCase, SelectSortTest) { SelectSort(nums); }

TEST_F(SortTestCase, InsertSortTest) { InsertSort(nums); }

TEST_F(SortTestCase, ShellSortTest) { ShellSort(nums); }

TEST_F(SortTestCase, MergeSortTest) { MergeSort(nums); }

TEST_F(SortTestCase, QuickSortTest) { QuickSort(nums); }

TEST_F(SortTestCase, BucketSortTest) {
  BucketSort(nums, *min_element(nums.begin(), nums.end()),
             *max_element(nums.begin(), nums.end()));
}