//
// Created by nigo on 2020/12/28.
//

#include "FileStream.h"

//获取int型选项
int FileStream::GetChoiceInt(int min, int max, const string& init_prompt, const string& wrg_prompt) {
  int choice;
  cout << init_prompt << flush;
  while (!(cin >> choice) || choice < min || choice > max) {
    cin.clear();
	while (getchar() != '\n');
	cout << wrg_prompt << flush;
  }
  while (getchar() != '\n');
  return choice;
}

string FileStream::GetFilename(const char *prompt) {
    static char *line_read = NULL;
    if (line_read)
    {
	    free (line_read);
	    line_read = (char *)NULL;
    }
    return line_read = readline(prompt);
/*	string s;
	printf("%s", prompt);
	getline(cin, s);
	return s;*/
}
//统计is中字符频率，存入w
void FileStream::AnalyseFrequency(istream &is, map<unsigned char, unsigned long> &w,
								  int &num) {
  unsigned char ch;
  num = 0;
  //对于一字节，无符号255即有符号-1
  while ((ch = is.get()) != 255) {
	w[ch]++;
	num++;
  }
}

//重新对ifs中字符编码，并存入ofs
//num:字符总数
//leaf_num:叶子节点个数
void FileStream::EncodeAndWrite(istream &is, ostream &os, map<unsigned char, string> &hcodes,
								map<unsigned char, unsigned long> &w,
								unsigned long num, unsigned long leaf_num) {
  //必须先将eofbit置位
  is.clear();
  is.seekg(0L, istream::beg);
  unsigned char ch;
  //写入num、leaf_num
  os.write((char*)&num, sizeof num);
  os.write((char*)&leaf_num, sizeof leaf_num);
  //写入w，以便重建w
  //从而重建HuffmanTreee
  auto j = w.begin();
  for (int i = 0; i < leaf_num; i++) {
	os.write((char*)&(j->first), sizeof j->first);
	os.write((char*)&(j->second), sizeof j->second);
	j++;
  }
  cout << "EncodeAndWrite" << endl;
  //写入HuffmanCode
  while ((ch = is.get()) != 255) {
    cout << hcodes[ch] << endl;
	WriteByBit(os, hcodes[ch]);
  }
}

//将string中内容按位写入os
void FileStream::WriteByBit(ostream &os, string &buffer) {
  os.write((char*)buffer.c_str(), buffer.size());
}

//将is中内容按位读入is
//读到'0',返回0
//读到'1',返回1
int FileStream::ReadByBit(istream &is) {
  unsigned char ch;
  is.read((char*)&ch, sizeof ch);
  return ch == '0' ? 0 : 1;
}

//读取Huf文件头
void FileStream::ReadHufHead(istream &is, map<unsigned char, unsigned long> &w,
							 unsigned long &num, unsigned long &leaf_num) {
  is.read((char*)&num, sizeof num);
  is.read((char*)&leaf_num, sizeof leaf_num);
  unsigned char ch;
  unsigned long weight;
  for (unsigned long i = 1; i <= leaf_num; i++) {
	is.read((char*)&ch, sizeof ch);
	is.read((char*)&weight, sizeof weight);
	w[ch] = weight;
  }
}

//获取文件大小
size_t FileStream::GetFileSize(const string &filename) {
  std::ifstream in(filename.c_str());
  in.seekg(0, ifstream::end);
  size_t size = in.tellg();
  in.close();
  return size;
}

//解码并写入
void FileStream::DecodeAndWrite(istream &is, ostream &os, const vector<HuffmanTree::HTNode> &htree,
								unsigned long num, unsigned long leaf_num) {
  unsigned long p;
  //只解码num个字符
  for (unsigned long i = 1; i <= num; ++i) {
    //根结点
    p = 2 * leaf_num - 1;
    while (htree[p].lchild) {
      if (ReadByBit(is) == 0)
        p = htree[p].lchild;
      else
        p = htree[p].rchild;
    }
	os.write((char*)&(htree[p].ch), sizeof htree[p].ch);
  }
}
