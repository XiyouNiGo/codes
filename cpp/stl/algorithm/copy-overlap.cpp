// file: 6copy-overlap.cpp

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct display {
  void operator()(const T& x) { cout << x << " "; }
};

// copy根据迭代器特性决定是否调用memmove

int main() {
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // 输出区间终点与输入区间重叠
    copy(ia + 2, ia + 7, ia);
    for_each(ia, ia + 9, display<int>());
    cout << endl;
    return 0;
  }

  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // 输出区间起点与输入区间重叠
    // 特化为memmove，正确
    copy(ia + 2, ia + 7, ia + 4);
    for_each(ia, ia + 9, display<int>());
    cout << endl;
  }

  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> id(ia, ia + 9);

    auto first = id.begin();
    auto last = id.end();
    ++++first;  // advance(first, 2);
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    auto result = id.begin();
    cout << *result << endl;

    // 输出区间终点与输入区间重叠
    copy(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;
  }

  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> id(ia, ia + 9);

    auto first = id.begin();
    auto last = id.end();
    ++++first;  // advance(first, 2);
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    auto result = id.begin();
    advance(result, 4);
    cout << *result << endl;

    // 输出区间起点与输入区间重叠
    // 换成vector则正确，因为vector的迭代器是原生指针
    copy(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;
  }
}