#include <bits/stdc++.h>

#include <cctype>
#include <fstream>

using namespace std;

class LexicalAnalyzer {
 public:
  LexicalAnalyzer() {
    vector<string> keywords = {
        "auto",
        "break",
        "case",
        "char",
        "const",
        "continue",
        "default",
        "do",
        "double",
        "else",
        "enum",
        "extern"
        "float",
        "for",
        "goto",
        "if",
        "int",
        "long",
        "register",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "struct"
        "switch",
        "typedef",
        "union",
        "unsigned",
        "void",
        "volatile",
        "while",
    };
    for (int i = 0; i < keywords.size(); i++) {
      symtable.insert({keywords[i], i});
    }
  }

  bool Analyse(string input, string ouput) {
    ifstream ifs(input);
    ofstream ofs(ouput);
    if (!ifs.is_open()) {
      cout << "Input file not exists." << endl;
      return false;
    }
    char ch = '\0';
    string buffer;
    int lineno = 0;
    // AlphaStatus as = AlphaStatus::kExpectUnderlineOrAlpha;
    while (!ifs.eof()) {
      ifs >> ch;
      if (isblank(ch)) {
        if (ch == '\n') {
          lineno++;
        }
        continue;
      }
      if (isalpha(ch)) {
        while (isalpha(ch) || isdigit(ch) || ch == '_') {
          if ((ch <=)) {
            
          }
        }
      }
    }
    return true;
  }

 private:
  unordered_map<string, int> symtable;
  // enum class AlphaStatus {
  //   kExpectUnderlineOrAlpha,
  //   kExpectAlpha,
  // };
};

int main(int argc, char *argv[]) { return 0; }