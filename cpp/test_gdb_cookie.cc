#include <bits/stdc++.h>

using namespace std;

template <int SIZE>
class TestGdbCookie {
 public:
  TestGdbCookie() : cur_(data_) { SetCookie(cookie_start); }

  ~TestGdbCookie() { SetCookie(cookie_end); }
  void Append(const char* buf, size_t len) {
    if (static_cast<size_t>(avail()) > len) {
      ::memcpy(cur_, buf, len);
      cur_ += len;
    }
  }

  const char* data() const { return data_; }
  int length() const { return static_cast<int>(cur_ - data_); }
  char* current() { return cur_; }
  int avail() const { return static_cast<int>(end() - cur_); }

  void Add(size_t len) { cur_ += len; }
  void Reset() { cur_ = data_; }
  void Bzero() { ::bzero(data_, sizeof data_); }
  void SetCookie(void (*cookie)()) { cookie_ = cookie; }

  static void cookie_start() {}
  static void cookie_end() {}

 private:
  const char* end() const { return data_ + sizeof data_; }

  // use info proc mappings, then find command to locate TestGdbCookie
  void (*cookie_)();
  char data_[SIZE];
  char* cur_;
};

int main(int argc, char* argv[]) {
  TestGdbCookie<1024> t;
  const char* data = "Hello Gdb Cookie";
  t.Append(data, strlen(data));
  return 0;
}
