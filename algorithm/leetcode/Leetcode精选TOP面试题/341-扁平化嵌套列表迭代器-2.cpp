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
  // pair:
  //  first: 指向当前访问位置
  //  second： 尾后迭代器
  stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>>
      stk;

 public:
  // 解法二： 栈
  // O(1) O(N)
  NestedIterator(vector<NestedInteger> &nestedList) {
    stk.emplace(nestedList.begin(), nestedList.end());
  }

  int next() { return stk.top().first++->getInteger(); }

  // hasNext将会在next之前被调用
  bool hasNext() {
    while (!stk.empty()) {
      auto &cur = stk.top();  // 注意是引用
      // 到达末尾
      if (cur.first == cur.second) {
        stk.pop();
        continue;
      }
      if (cur.first->isInteger()) {
        return true;
      } else {
        // 若为列表，入栈，并将迭代器指向下一个元素
        auto &list = cur.first++->getList();
        stk.emplace(list.begin(), list.end());
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }