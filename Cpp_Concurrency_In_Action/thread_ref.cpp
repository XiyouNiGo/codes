#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void thread_func(string& data) {
  printf("thread : initial data is %s\n", data.c_str());

  data.assign("child thread's data");
  printf("thread : data altered\n");

  printf("thread : final data is %s\n", data.c_str());
}

int main(int argc, char *argv[]) {
  const char* base = "main thread's data";
  string data(base);
  printf("main : initial data is %s\n", data.c_str());
//  thread t(thread_func, data);
  thread t(thread_func, ref(data));

  sleep(5);

  data.compare(base) ?
  	cout << "book is wrong" << endl :
  	cout << "book is correct" << endl;
  t.join();
  return 0;
}
