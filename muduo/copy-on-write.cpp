#include <bits/stdc++.h>
#include <boost/noncopyable.hpp>
#include <muduo/base/Mutex.h>

using namespace std;
using namespace muduo;

class Foo {
 public:
  void doit();
};

typedef std::vector<Foo> FooList;
typedef std::shared_ptr<FooList> FooListPtr;
MutexLock mutex;
FooListPtr g_foos;

//利用mutex和shared_ptr取代读写锁
//避免死锁，且不阻塞读操作
//读写锁开销比mutex大，且写锁优先，会阻塞后面的读锁
void traverse() {
  FooListPtr foos;
  {
    MutexLockGuard lock(::mutex);
    //引用计数++
    foos = g_foos;
    assert(!g_foos.unique());
  }
  for (auto it = foos->begin(); it != foos->end(); ++it) {
    //即使doit调用post也不会死锁
    it->doit();
  }
}

void post(const Foo& f) {
  MutexLockGuard lock(::mutex);
  //写操作能检测是否有人在读
  if (!g_foos.unique()) {
    //copy-on-write
    g_foos.reset(new FooList(*g_foos));
    //此时读操作读的是稍久的版本
  }
  assert(g_foos.unique());
  g_foos->push_back(f);
}

int main(int argc, char *argv[]) {
  return 0;
}
