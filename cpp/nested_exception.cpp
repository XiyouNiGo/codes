#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void print_exception(const std::exception& e, int level = 0) {
  std::cerr << std::string(level, ' ') << "exception: " << e.what() << '\n';
  try {
    std::rethrow_if_nested(e);
  } catch (const std::exception& e) {
    print_exception(e, level + 1);
  } catch (...) {
  }
}

void open_file(const std::string& s) {
  try {
    std::ifstream file(s);
    file.exceptions(std::ios_base::failbit);
  } catch (...) {
    std::throw_with_nested(std::runtime_error("Couldn't open " + s));
  }
}

/*std::nested_exception is a polymorphic mixin class which can capture and store
 * the current exception, making it possible to nest exceptions of arbitrary
 * types within each other.  */
void run() {
  try {
    open_file("nonexistent.file");
  } catch (...) {
    std::throw_with_nested(std::runtime_error("run() failed"));
  }
}

int main() {
  try {
    run();
  } catch (const std::exception& e) {
    print_exception(e);
  }
}