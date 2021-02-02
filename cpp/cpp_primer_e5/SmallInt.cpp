#include <bits/stdc++.h>

using namespace std;

class SmallInt {
 private:
  std::size_t val;
 public:
  SmallInt(int i = 0) : val(i) {
    if (i < 0 || i > 255)
      throw std::out_of_range("Bad SmallInt value");
  }
  operator int() const { return val; }
};

int main(int argc, char *argv[]) {
  SmallInt si(4);
  si + 3;
  si + 3.14;
  return 0;
}
