#include <bits/stdc++.h>

// using namespace std;

class alloc {};

template <class T, class Alloc = alloc>
class vector {
 public:
  void swap(vector<T, Alloc &>) { cout << "swap()" << endl; }
};

int main(int argc, char *argv[]) { 
  vector<int> x, y;
  swap(x, y);
  return 0; 
}
