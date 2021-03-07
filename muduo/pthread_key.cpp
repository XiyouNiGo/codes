#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

//不同线程对应的value值不同
pthread_key_t key;

void pk_destroy_func(void *arg) {
  //相当于打印多次...
  //可能出现交叉输出，但保证每次输出原子性
  cout << "pthread_key destroyed in " << arg
       << endl;
}

void* thread_func(void* arg) {
  pthread_t tid = pthread_self();
  pthread_setspecific(key, &tid);
  cout << "thread " << *(int*)arg << " : "
       << "tid is " << *(pthread_t*)pthread_getspecific(key)
       << endl;
}

int main(int argc, char *argv[]) {
  pthread_key_create(&key, pk_destroy_func);
  vector<pthread_t> t_vec(5);
  for (auto &t : t_vec) {
    static int n = 0;
    pthread_create(&t, NULL, thread_func, &n);
    n++;
  }
  for (auto &t : t_vec) {
	waitpid(t, NULL, 0);
	cout << "hhh" << endl;
  }
  pthread_key_delete(key);
  return 0;
}
