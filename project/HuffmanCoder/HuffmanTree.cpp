//
// Created by nigo on 2020/12/28.
//

#include "HuffmanTree.h"

//HuffmanTree构造函数，使用静态三叉链表实现
//leaf_num：叶子节点个数
//file_stream：自定义文件流对象
HuffmanTree::HuffmanTree(map<unsigned char, unsigned long> w)
	: leaf_num(w.size()), total_num(w.size()*2-1), htree(w.size()*2) {
  //初始化哈夫曼树（下标从1开始）
  auto j = w.begin();
  for (int i = 1; i <= leaf_num; ++i) {
	htree[i].weight = (*j).second;
	htree[i].ch = (*j).first;
	++j;
  }
  //选择weight最小的两个节点
  //分别作为左右节点，构造新节点
  //total_num = n0 + n2 = 2 * n2 - 1
  for (unsigned long i = leaf_num+1; i <= total_num; ++i) {
	auto i_min_two = SelectMinTwo(htree, i);
	auto i_min1 = i_min_two.first;
	auto i_min2 = i_min_two.second;
	htree[i].lchild = i_min1;
	htree[i].rchild = i_min2;
	htree[i].weight = htree[i_min1].weight + htree[i_min2].weight;
	htree[i_min1].parent = htree[i_min2].parent = i;
  }
}

//使用pair返回weight最小的两个节点
pair<unsigned long, unsigned long> HuffmanTree::SelectMinTwo(vector<HTNode> htree, unsigned long end) {
  unsigned long min1, min2, i_min1, i_min2;
  //min1:最小值
  //min2:次小值
  min1 = min2 = ULONG_MAX;
  i_min1 = i_min2 = 0;
  //只遍历一遍，找出最小的两个数
  for (int i = 1; i < end; ++i) {
	if (!htree[i].parent && htree[i].weight < min1) {
	  min2 = min1;
	  min1 = htree[i].weight;
	  i_min2 = i_min1;
	  i_min1 = i;
	}
	else if (!htree[i].parent && htree[i].weight < min2) {
	  min2 = htree[i].weight;
	  i_min2 = i;
	}
  }
  return pair<unsigned long, unsigned long>(i_min1, i_min2);
}

//生成Huffman编码，保存在hcodes
void HuffmanTree::GenerateHuffmanCode(map<unsigned char, string> &hcodes) {
  //先用deque形成编码
  //再拷贝到string中
  deque<char> temp;
  unsigned long parent, child;
  for (unsigned long i = 1; i <= leaf_num; ++i) {
	child = i;
	parent = htree[i].parent;
	//循环直到根结点结束
	while (parent) {
	  //左孩子编码0，右孩子编码1
	  if (htree[parent].lchild == child)
	    temp.push_front('0');
	  else
	    temp.push_front('1');
	  child = parent;
	  parent = htree[parent].parent;
	}
	hcodes[htree[i].ch] = string(temp.begin(), temp.end());
	temp.clear();
  }
}

//重载<<运算符，输出HuffmanTree到ostream
ostream &operator<<(ostream &os, HuffmanTree &htree) {
  cout << setw(8) << "weight"
	   << setw(8) << "parent"
	   << setw(8) << "lchild"
	   << setw(8) << "rchild"
	   << setw(8) << "i"
	   << setw(8) << "ASCII" << endl;
  for (unsigned long i = 0; i < htree.htree.size(); ++i) {
	os << setw(8) << htree.htree[i].weight;
	os << setw(8) << htree.htree[i].parent;
	os << setw(8) << htree.htree[i].lchild;
	os << setw(8) << htree.htree[i].rchild;
	os << setw(8) << i;
	os << setw(8) << (unsigned int)htree.htree[i].ch << endl;
  }
  return os;
}

//获取leaf_num（private成员）
unsigned long HuffmanTree::GetLeafNum() const {
  return leaf_num;
}

//获取htree
const vector<HuffmanTree::HTNode> &HuffmanTree::GetHtree() const {
  return htree;
}