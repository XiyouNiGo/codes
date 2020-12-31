//
// Created by nigo on 2020/12/28.
//

#ifndef HUFFMAN_CODER__HUFFMANTREE_H_
#define HUFFMAN_CODER__HUFFMANTREE_H_

#include <bits/stdc++.h>
using namespace std;

class HuffmanTree {
 public:
  typedef struct {
	unsigned long weight;		//权值
	unsigned long parent;		//父节点
	unsigned long lchild;		//左孩子
	unsigned long rchild;		//右孩子
	unsigned char ch;			//字符
  }HTNode;

  explicit HuffmanTree(map<unsigned char, unsigned long> w);
  void GenerateHuffmanCode(map<unsigned char, string> &hcodes);
  unsigned long GetLeafNum() const;
  const vector<HTNode> &GetHtree() const;
  friend ostream &operator<<(ostream &os, HuffmanTree &htree);
 private:
  unsigned long leaf_num;
  unsigned long total_num;
  vector<HTNode> htree;
  static pair<unsigned long, unsigned long> SelectMinTwo(vector<HTNode> htree, unsigned long end);
};

#endif //HUFFMAN_CODER__HUFFMANTREE_H_