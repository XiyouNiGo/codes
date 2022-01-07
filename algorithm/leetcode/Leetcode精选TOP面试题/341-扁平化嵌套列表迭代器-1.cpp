#include <bits/stdc++.h>

#include <vector>

using namespace std;

class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested st.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single teger The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  vector<int> integers_;
  int cur_;

  void dfs(const vector<NestedInteger> &nestedList) {
    for (auto &i : nestedList) {
      if (i.isInteger()) {
        integers_.push_back(i.getInteger());
      } else {
        dfs(i.getList());
      }
    }
  }

 public:
  // 解法一： DFS
  // 初始化： O(N)
  // next： O(1)
  // hasNext： O(1)
  // O(N)
  NestedIterator(vector<NestedInteger> &nestedList) : cur_(0) {
    dfs(nestedList);
  }

  int next() { return integers_[cur_++]; }

  bool hasNext() { return cur_ != integers_.size(); }
};

int main(int argc, char *argv[]) { return 0; }