#include <bits/stdc++.h>
#include <boost/noncopyable.hpp>

using namespace std;

//RAII
class MutexLock : boost::noncopyable {
 public:
  MutexLock() : holder_(0) {
    pthread_mutex_init(&mutex_, NULL);
  }

  ~MutexLock() {
    assert(holder_ == 0);
    pthread_mutex_destroy(&mutex_);
  }

  bool isLockedByThisThread() {
//    return holder_ == CurrentThread::tid();
  }

  void assertLocked() {
    assert(isLockedByThisThread());
  }

  void lock() {
    pthread_mutex_lock(&mutex_);
//	holder_ = CurrentThread::tid();
  }

  void unlock() {
    pthread_mutex_unlock(&mutex_);
    holder_ = 0;
  }

  pthread_mutex_t* getPthreadMutex() {
    return &mutex_;
  }

 private:
  pthread_mutex_t mutex_;
  pid_t holder_;
};

class MutexLockGuard : boost::noncopyable {
 public:
  explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex){
    mutex_.lock();
  }

  ~MutexLockGuard() {
    mutex_.unlock();
  }
 private:
  MutexLock& mutex_;
};

//静态断言(编译期的断言）
#define MutexLockGuard(x) static_assert(false, "missing mutex guard var name");

int main(int argc, char *argv[]) {
    return 0;
}
