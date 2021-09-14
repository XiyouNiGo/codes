#include <bits/stdc++.h>

namespace outside
{
  namespace inside
  {
    const std::string inside_string = "Access inside string successfully";
  } // namespace inside
  void print() {
    std::cout << inside::inside_string << std::endl;
  }
} // namespace outside

int main(int argc, char *argv[]) {
  outside::print();
  return 0; 
}
