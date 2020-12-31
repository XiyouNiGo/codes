//
// Created by nigo on 2020/12/28.
//

#ifndef HUFFMANCODER__FILESTREAM_H_
#define HUFFMANCODER__FILESTREAM_H_

#include <bits/stdc++.h>
#include <readline/readline.h>
#include "HuffmanTree.h"
using namespace std;

class FileStream {
 public:
  static int GetChoiceInt(int min, int max, const string& init_prompt, const string& wrg_prompt);
  static string GetFilename(const char *prompt);
  static void AnalyseFrequency(istream &is, map<unsigned char, unsigned long> &w, int &num);
  static void EncodeAndWrite(istream &is, ostream &os, map<unsigned char, string> &hcodes,
							 map<unsigned char, unsigned long> &w,
							 unsigned long num, unsigned long leaf_num);
  static void DecodeAndWrite(istream &is, ostream &os, const vector<HuffmanTree::HTNode> &htree,
							 unsigned long num, unsigned long leaf_num);
  static void ReadHufHead(istream &is, map<unsigned char, unsigned long> &w,
						  unsigned long &num, unsigned long &leaf_num);
  static void WriteByBit(ostream &os, string &buffer);
  static int ReadByBit(istream &is);
  static size_t GetFileSize(const std::string& filename);
};

#endif //HUFFMANCODER__FILESTREAM_H_