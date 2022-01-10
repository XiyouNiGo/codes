#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
  unordered_map<Node*, Node*> old2new;

 public:
  // 解法三： 递归 + 哈希表
  // O(N) O(N)
  // 返回旧节点对应的新节点
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return head;
    }
    // 每个旧节点干三件事：
    //  1. 复制当前节点
    //  2. 将next设为新next节点
    //  3. 将random设为新random节点
    auto it = old2new.find(head);
    if (it == old2new.end()) {
      Node* p = new Node(head->val);
      old2new[head] = p;
      p->next = copyRandomList(head->next);
      p->random = copyRandomList(head->random);
      return p;
    } else {
      return it->second;
    }
  }
};

int main(int argc, char* argv[]) { return 0; }