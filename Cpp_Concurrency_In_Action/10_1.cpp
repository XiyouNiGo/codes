#include <execution>
#include <iostream>
#include <mutex>

using namespace std;

class X{
    mutable std::mutex m;
    int data;
public:
    X():data(0){}
    int get_value() const{
        std::lock_guard guard(m);
        return data;
    }
    void increment(){
        std::lock_guard guard(m);
        ++data;
    }
};
void increment_all(std::vector<X>& v){
    /* no error happens in my machine */
    std::for_each(std::execution::par_unseq,v.begin(),v.end(),
        [](X& x){
            x.increment();
        });
}

int main(int argc, char* argv[]) {
  vector<X> v(100000);
  increment_all(v);
  for (auto &i : v) {
      cout << i.get_value() << endl;
  }
}