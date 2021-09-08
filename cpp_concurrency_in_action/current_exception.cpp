#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void handle_eptr(std::exception_ptr eptr)
{
  try {
    if (eptr) {
      std::rethrow_exception(eptr);
    }
  } catch (const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
  }
}

int main() {
  std::exception_ptr eptr;
  try {
    /* std::out_of_range */
    std::string().at(1);
  } catch (...) {
    eptr = std::current_exception();
  }
  handle_eptr(eptr);
}