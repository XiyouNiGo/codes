//
// Created by nigo on 2021/1/22.
//

#include "my_string.h"

my_string operator+ (const my_string& lhs, const my_string& rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (my_string&&      lhs, my_string&&      rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (my_string&&      lhs, const my_string& rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (const my_string& lhs, my_string&&      rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (const my_string& lhs, const char*   rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (my_string&&      lhs, const char*   rhs) {
  return my_string::do_addition(lhs, rhs);

}

my_string operator+ (const char*   lhs, const my_string& rhs) {
  return my_string::do_addition(lhs, rhs);

}

my_string operator+ (const char*   lhs, my_string&&      rhs) {
  return my_string::do_addition(lhs, rhs);
}

my_string operator+ (const my_string& lhs, char          rhs) {
  return my_string::do_addition(lhs, my_string(rhs, 1));
}

my_string operator+ (my_string&&      lhs, char          rhs) {
  return my_string::do_addition(lhs, my_string(rhs, 1));

}

my_string operator+ (char          lhs, const my_string& rhs) {
  return my_string::do_addition(my_string(lhs, 1), rhs);
}

my_string operator+ (char          lhs, my_string&&      rhs) {
  return my_string::do_addition(my_string(lhs, 1), rhs);
}

bool operator== (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) == 0;
}

bool operator== (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) == rhs;
}

bool operator== (const my_string& lhs, const char*   rhs) {
  return lhs == my_string(rhs);
}

bool operator!= (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) != 0;
}

bool operator!= (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) != rhs;
}

bool operator!= (const my_string& lhs, const char*   rhs) {
  return lhs != my_string(rhs);
}

bool operator< (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) == -1;
}

bool operator< (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) < rhs;
}

bool operator< (const my_string& lhs, const char*   rhs) {
  return lhs < my_string(rhs);
}

bool operator<= (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) != 1;
}

bool operator<= (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) <= rhs;
}

bool operator<= (const my_string& lhs, const char*   rhs) {
  return lhs <= my_string(rhs);
}

bool operator>  (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) == 1;
}

bool operator>  (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) > rhs;
}

bool operator>  (const my_string& lhs, const char*   rhs) {
  return lhs > my_string(rhs);
}

bool operator>= (const my_string& lhs, const my_string& rhs) {
  return lhs.compare(rhs) != -1;
}

bool operator>= (const char*   lhs, const my_string& rhs) {
  return my_string(lhs) >= rhs;
}

bool operator>= (const my_string& lhs, const char*   rhs) {
  return lhs >= my_string(rhs);
}

void swap (my_string& x, my_string& y) {
  std::swap(x._buffer, y._buffer);
  std::swap(x._size, y._size);
  std::swap(x._capacity, y._capacity);
}

std::istream& operator>> (std::istream& is, my_string& str) {
  return getline(is, str, '\n');
}

std::ostream& operator<< (std::ostream& os, const my_string& str) {
  return os.write(str.c_str(), str.size());
}

std::istream& getline (std::istream&  is, my_string& str, char delim) {
  int ch;
  str.clear();
  while ((ch = is.get()) != -1 || (ch != delim) || (ch != '\n'))
    str.push_back(ch);
  return is;
}

std::istream& getline (std::istream&& is, my_string& str, char delim) {
  int ch;
  str.clear();
  while ((ch = is.get()) != -1 || (ch != delim) || (ch != '\n'))
	str.push_back(ch);
  return is;
}

std::istream& getline (std::istream&  is, my_string& str) {
  return getline(is, str, '\n');
}

std::istream& getline (std::istream&& is, my_string& str) {
  return getline(is, str, '\n');
}