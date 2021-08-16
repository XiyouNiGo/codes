#include <bits/stdc++.h>

using namespace std;

void thread_func() { std::this_thread::sleep_for(std::chrono::seconds(5)); }

int main(int argc, char *argv[]) {
  packaged_task<void()> task(thread_func);
  thread t(move(task));
  /* terminate called after throwing an instance of 'std::future_error'
  what():  std::future_error: No associated state */
  { future<void> f = task.get_future(); }
  return 0;
}
