#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
  priority_queue<int, vector<int>, less<int>> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap.size() == min_heap.size()) {
      max_heap.push(num);
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else {
      min_heap.push(num);
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    return max_heap.size() == min_heap.size()
               ? (max_heap.top() + min_heap.top()) * 1.0/ 2
               : min_heap.top() * 1.0;
  }
};

int main(int argc, char *argv[]) { return 0; }
