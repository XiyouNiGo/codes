#include <bits/stdc++.h>

#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::iterator> key2node;
  int capacity_;

 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (key2node.count(key) == 0) {
      return -1;
    }
    auto node = *key2node[key];
    cache.erase(key2node[key]);
    cache.push_front(node);
    key2node[key] = cache.begin();
    return node.second;
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      cache.front().second = value;
      return;
    }
    if (cache.size() >= capacity_) {
      key2node.erase(cache.back().first);
      cache.pop_back();
    }
    cache.push_front(make_pair(key, value));
    key2node[key] = cache.begin();
  }
};

int main(int argc, char *argv[]) { return 0; }