#include <bits/stdc++.h>

using namespace std;

//RAII对象
//在构造过程中获得资源
//在析构过程中归还
class NewHandlerHolder {
 public:
  explicit NewHandlerHolder(std::new_handler nh) : handler(nh) { }
  ~NewHandlerHolder() {
      std::set_new_handler(handler);
  }
 private:
  std::new_handler handler;
  NewHandlerHolder(const NewHandlerHolder&) = delete;
  NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;
};

class Widget {
 public:
  static std::new_handler set_new_handler(std::new_handler p) throw() {
    std::new_handler old_handler = current_handler;
    current_handler = p;
    return old_handler;
  }

  //默认是static函数
  void* operator new(std::size_t size) throw(std::bad_alloc) {
    NewHandlerHolder h(std::set_new_handler(current_handler));
    return ::operator new(size);
  }
 private:
  static std::new_handler current_handler;
};

int main(int argc, char *argv[]) {
  //使用方式
  std::new_handler nh;
  Widget::set_new_handler(nh);
  Widget *pw = new Widget;
  return 0;
}
