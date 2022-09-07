#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
 public:
  struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };

  // 初始化链表
  MyLinkedList() {
    _dummy = new LinkedNode(0);
    _size = 0;
  }

  int get(int index) {
    if (index > (_size - 1) || index < 0) {
      return -1;
    }
    LinkedNode* cur = _dummy->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    newNode->next = _dummy->next;
    _dummy->next = newNode;
    _size++;
  }

  void addAtTail(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummy;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = newNode;
    _size++;
  }

  void addAtIndex(int index, int val) {
    if (index > _size || index < 0) {
      return;
    }
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = _dummy;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    _size++;
  }

  void deleteAtIndex(int index) {
    if (index >= _size || index < 0) {
      return;
    }
    LinkedNode* cur = _dummy;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    _size--;
  }

 private:
  int _size;
  LinkedNode* _dummy;
};

int main(int argc, char* argv[]) { return 0; }