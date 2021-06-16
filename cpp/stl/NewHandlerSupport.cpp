#include <bits/stdc++.h>

using namespace std;

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

//让类拥有专属的new-handler的能力
//只需要让类继承该类模板的实例即可
template<typename T>
class NewHandlerSupport {
 public:
  static std::new_handler set_new_handler(std::new_handler p) throw() {
	std::new_handler old_handler = current_handler;
	current_handler = p;
	return old_handler;
  }

  void* operator new(std::size_t size) throw(std::bad_alloc) {
	NewHandlerHolder h(std::set_new_handler(current_handler));
	return ::operator new(size);
  }

 private:
  static std::new_handler current_handler;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::current_handler = nullptr;

int main(int argc, char *argv[]) {
    return 0;
}
