#include <string>
#include <future>

struct X {
  void foo(int, std::string const &);
  std::string bar(std::string const &);
};

X x;
auto f1 = std::async(&X::foo, &x, 42, "hello");	// a pointer
auto f2 = std::async(&X::bar, x, "goodbye");	// a copy

struct Y {
  double operator()(double);
};
Y y;
auto f3 = std::async(Y(), 3.141);
auto f4 = std::async(std::ref(y), 2.718);
X baz(X &);
auto f6 = std::async(baz, std::ref(x));
class move_only {
 public:
  move_only();
  move_only(move_only &&);
  move_only(move_only const &) = delete;
  move_only &operator=(move_only &&);
  move_only &operator=(move_only const &) = delete;
  void operator()();
};
auto f5 = std::async(move_only());
auto f6=std::async(std::launch::async,Y(),1.2); // 在新线程上执行
auto f7=std::async(std::launch::deferred,baz,std::ref(x)); // 在wait()或get()调用时执行
auto f8=std::async( std::launch::deferred | std::launch::async, baz,std::ref(x)); // 实现选择执行方式
auto f9=std::async(baz,std::ref(x));f7.wait(); // 调用延迟函数
