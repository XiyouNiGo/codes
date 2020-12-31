#include <bits/stdc++.h>
#include "FileStream.h"
#include "HuffmanTree.h"

using namespace std;

inline void my_err(const char *err_msg) {
	fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__);
	perror(err_msg);
	exit(1);
}

int main(int argc, char **argv) {
  int choice = FileStream::GetChoiceInt(0, 2, "Enter your choice(0:encode 1:decode 2:tool information) : ",
							"Wrong choice, enter again : ");
  switch (choice) {
    case 0: {
	  string input_filename = FileStream::GetFilename(
		  "Enter the input filename(Tab to completion) : ");
	  ifstream input_file(input_filename);
	  if (!input_file) {
		cout << "File not found!" << endl;
		break;
	  }

	  string output_filename = FileStream::GetFilename(
		  "Enter the output filename(suffix '.huf') : ");
	  output_filename += ".huf";
	  fstream output_file(output_filename);	//输出文件
	  if (output_file.is_open()) {
		choice = FileStream::GetChoiceInt(0, 1, "File existed, do you wanna cover it?(0:yes 1:no) : ",
										  "Wrong choice, enter again : ");
		if (choice == 1) {
		  cout << "Data is priceless!" << endl;
		  break;
		}
	  }
	  output_file.close();
	  output_file.open(output_filename, fstream::out | fstream::trunc);
	  if (!output_file.is_open()) {
	    my_err("File error!");
	  }

	  cout << "Before encoded : " << FileStream::GetFileSize(input_filename)
	  	   << " Bytes" << endl;
	  cout << "Encoding..." << endl;
	  map<unsigned char, unsigned long> w;
	  int num;	//字符总数
	  FileStream::AnalyseFrequency(input_file, w, num);
	  HuffmanTree htree(w);
	  cout << htree;
	  map<unsigned char, string> hcodes;
	  htree.GenerateHuffmanCode(hcodes);
	  FileStream::EncodeAndWrite(input_file, output_file, hcodes, w, num, htree.GetLeafNum());
	  cout << "Before encoded : " << FileStream::GetFileSize(output_filename)
		   << " Bytes" << endl;
	  cout << "Done!" << endl;
	  break;
	}
    case 1: {
      string input_filename = FileStream::GetFilename(
      			    "Enter the input filename : ");
	  if (input_filename.find(".huf") != input_filename.size() - 4) {
	    my_err("Unrecognized file!");
	  }
	  ifstream input_file(input_filename);
      if (!input_file.is_open()) {
        my_err("File error!");
      }

	  string output_filename = FileStream::GetFilename(
		  "Enter the output filename : ");
	  fstream output_file(output_filename);
	  if (output_file.is_open()) {
		choice = FileStream::GetChoiceInt(0, 1, "File existed, do you wanna cover it?(0:yes 1:no) : ",
										  "Wrong choice, enter again : ");
		if (choice == 1) {
		  cout << "Data is priceless!" << endl;
		  break;
		}
	  }
	  output_file.close();
	  output_file.open(output_filename, fstream::out | fstream::trunc);
	  if (!output_file.is_open()) {
		my_err("File error!");
	  }

	  cout << "Decoding..." << endl;
      unsigned long leaf_num, num;
      map<unsigned char, unsigned long> w;
      FileStream::ReadHufHead(input_file, w, num, leaf_num);
//      for (auto &i : w) {
//        cout << i.first << " " << i.second << endl;
//      }
      HuffmanTree htree(w);
      cout << htree;
//      map<unsigned char, string> hcodes;
//	  htree.GenerateHuffmanCode(hcodes);
      FileStream::DecodeAndWrite(input_file, output_file, htree.GetHtree(),
								 num, leaf_num);
      cout << "Done!" << endl;
	  break;
	}
	case 2: {
      cout << "**************************" << endl;
      cout << "--> Name   : HuffmanCoder " << endl;
      cout << "--> Author : NiGo         " << endl;
      cout << "--> Time   : 2020-12-28   " << endl;
	  cout << "--> Intented for encoding " << endl
	       << "and decoding text files   " << endl;
	  cout << "--> Thank you for using   " << endl;
	  cout << "**************************" << endl;
	  break;
	default:
	  my_err("choice error");
	}
  }
  return 0;
}