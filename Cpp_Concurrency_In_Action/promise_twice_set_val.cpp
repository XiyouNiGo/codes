#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  promise<void> result;
  future<void> f = result.get_future();
  /* terminate called after throwing an instance of 'std::system_error'
  what():  Unknown error -1 */
  result.set_value();
  result.set_value();
  return 0;
}
