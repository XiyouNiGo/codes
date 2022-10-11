#include <bits/stdc++.h>

#include <utility>

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

  bool Insert(const std::pair<K, V> &kv) {
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
    while (parent) {
      if (parent->_left == cur) {
        parent->_bf--;
      } else {
        parent->_bf++;
      }
      assert(parent->_bf >= -2 && parent->_bf <= 2);
      if (parent->_bf == 0) {
        break;
      }
      if (parent->_bf == -1 || parent->_bf == 1) {
        cur = parent;
        parent = parent->_parent;
      } else {
        if (parent->_bf == -2) {
          if (cur->_bf == -1) {
            RotateR(parent);
          } else {
            RotateLR(parent);
          }
        } else {
          if (cur->_bf == 1) {
            RotateL(parent);
          } else {
            RotateRL(parent);
          }
        }
      }
    }
    return true;
  }

  std::pair<Node *, bool> Insert(const std::pair<K, V> kv) {
    if (_root == nullptr) {
      _root = new Node(kv);
      return std::make_pair(_root, true);
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
        return std::make_pair(nullptr, false);
      }
    }
    // insert
    cur = new Node(kv);
    Node *newNode = cur;
    if (parent->_kv < kv.first) {
      parent->_right = cur;
    } else {
      parent->_left = cur;
    }
    cur->_parent = parent;
    while (parent) {
      if (parent->_left == cur) {
        parent->_bf--;
      } else {
        parent->_bf++;
      }
      assert(parent->_bf >= -2 && parent->_bf <= 2);
      if (parent->_bf == 0) {
        break;
      }
      if (parent->_bf == -1 || parent->_bf == 1) {
        cur = parent;
        parent = parent->_parent;
      } else {
        if (parent->_bf == -2) {
          if (cur->_bf == -1) {
            RotateR(parent);
          } else {
            RotateLR(parent);
          }
        } else {
          if (cur->_bf == 1) {
            RotateL(parent);
          } else {
            RotateRL(parent);
          }
        }
      }
    }
    return std::make_pair(newNode, true);
  }

  bool Erase(const K &key) {
    Node *cur = _root, *parent = cur;
    // 跟删除二叉搜索树的节点一样
    while (cur) {
      if (cur->_kv.first < key) {
        parent = cur;
        cur = cur->_right;
      } else if (cur->kv.first > key) {
        parent = cur;
        cur = cur->left;
      } else {
        if (cur->_left == nullptr) {
          if (cur == _root) {
            _root = cur;
          } else {
            if (parent->_right == cur) {
              parent->_right = cur->_right;
            } else {
              parent->_left = cur->_right;
            }
          }
          delete cur;
        } else if (cur->_right == nullptr) {
          if (cur == _root) {
            _root = cur;
          } else {
            if (parent->_right == cur) {
              parent->_right = cur->_left;
            } else {
              parent->_left = cur->_left;
            }
          }
          delete cur;
        } else {
          // 选择左子树的最右节点
          Node *leftMax = cur->_left;
          Node *leftMaxParent = cur;
          while (leftMax->_right) {
            leftMaxParent = leftMax;
            leftMax = leftMax->_right;
          }
          std::swap(cur->_kv, leftMax->_kv);
          leftMaxParent->_right = leftMax->_left;
          delete leftMax;
        }
        break;
      }
    }
    if (cur == nullptr) {
      return false;
    }
    while (parent) {
      if (parent->_left == cur) {
        parent->_bf--;
      } else {
        parent->_bf++;
      }
      assert(parent->_bf >= -2 && parent->_bf <= 2);
      if (parent->_bf == 0) {
        break;
      }
      if (parent->_bf == -1 || parent->_bf == 1) {
        cur = parent;
        parent = parent->_parent;
      } else {
        if (parent->_bf == -2) {
          if (cur->_bf == -1) {
            RotateR(parent);
          } else {
            RotateLR(parent);
          }
        } else {
          if (cur->_bf == 1) {
            RotateL(parent);
          } else {
            RotateRL(parent);
          }
        }
      }
    }
    return true;
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