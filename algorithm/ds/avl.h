#include <bits/stdc++.h>

template <typename K, typename V>
struct AVLTreeNode {
  int _bf;  // balance factor
  std::pair<K, V> _kv;
  AVLTreeNode<K, V> _left;
  AVLTreeNode<K, V> _right;
  AVLTreeNode<K, V> _parent;
  AVLTreeNode(const std::pair<K, V> &kv)
      : _bf(0), _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr) {}
};

template <typename K, typename V>
class AVLTree {
  using Node = AVLTreeNode<K, V>;

  Node *Find(const K &key) {
    Node *cur = _root;
    while (cur) {
      if (cur->_kv.first < key) {
        cur = cur->_right;
      } else if (cur->kv.first > key) {
        cur = cur->left;
      } else {
        return cur;
      }
    }
    return nullptr;
  }

  bool Insert(const std::pair<K, V> kv) {
    if (_root == nullptr) {
      _root = new Node(kv);
      return true;
    }
    Node *cur = _root, *parent = cur;
    // find
    while (cur) {
      if (cur->_kv.first < kv.first) {
        parent = cur;
        cur = cur->_right;
      } else if (cur->kv.first > kv.first) {
        parent = cur;
        cur = cur->left;
      } else {
        return false;
      }
    }
    // insert
    cur = new Node(kv);
    if (parent->_kv < kv.first) {
      parent->_right = cur;
    } else {
      parent->_left = cur;
    }
    cur->_parent = parent;
  }

 private:
  Node *_root;
  // RR
  void RotateR(Node *parent) {
    Node *subL = parent->_left;
    Node *subLR = subL->_right;
    Node *pParent = parent->_parent;
    // 1
    parent->_left = subLR;
    if (subLR) {
      subLR->_parent = parent;
    }
    // 2
    subL->_right = parent;
    parent->_parent = subL;
    // 3
    if (parent == _root) {
      _root = subL;
      subL->_parent = nullptr;
    } else {
      if (pParent->_left == parent) {
        pParent->_left = subL;
      } else {
        pParent->_right = subL;
      }
      subL->_parent = pParent;
    }
    subL->_bf = 0;
  }

  // LL
  void RotateL(Node *parent) {
    Node *subR = parent->_right;
    Node *subRL = subR->_left;
    Node *pParent = parent->_parent;
    // 1
    parent->_right = subRL;
    if (subRL) {
      subRL->_parent = parent;
    }
    // 2
    subR->_left = parent;
    parent->_parent = subR;
    // 3
    if (parent == _root) {
      _root = subR;
      subR->_parent = nullptr;
    } else {
      if (pParent->_right == parent) {
        pParent->_right = subR;
      } else {
        pParent->_left = subR;
      }
      subR->_parent = pParent;
    }
    subR->_bf = 0;
  }

  // LR:先对左子树左旋，再对根节点右旋
  void RotateLR(Node *parent) {
    Node *subL = parent->_left;
    Node *subLR = subL->_right;
    int bf = subLR->_bf;
    RotateL(subL);
    RotateR(subL);
    if (bf == 1) {
      parent->_bf = 0;
      subL->_bf = -1;
      subLR->_bf = 0;
    } else if (bf == -1) {
      parent->_bf = 1;
      subL->_bf = 0;
      subLR->_bf = 0;
    } else {
      parent->_bf = 0;
      subL->_bf = 0;
      subLR->_bf = 0;
    }
  }

  // RL:先对右子树右旋，再对根节点左旋
  void RotateRL(Node *parent) {
    Node *subR = parent->_right;
    Node *subRL = subR->_left;
    int bf = subRL->_bf;
    RotateL(subR);
    RotateR(subR);
    if (bf == 1) {
      parent->_bf = 0;
      subR->_bf = -1;
      subRL->_bf = 0;
    } else if (bf == -1) {
      parent->_bf = 1;
      subR->_bf = 0;
      subRL->_bf = 0;
    } else {
      parent->_bf = 0;
      subR->_bf = 0;
      subRL->_bf = 0;
    }
  }
};