#include <stdio.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  time_t time_now = time(NULL);
  time_t time_end = time_now + 2000;

  struct tm p_tm = {0};
  struct tm p_tm_end = {0};
  // we cant use localtime twice
  localtime_r(&time_now, &p_tm);
  localtime_r(&time_end, &p_tm_end);

  char buf_tm[50] = {0};
  strftime(buf_tm, 50, "%H:%M:%S", &p_tm);
  char buf_tm_end[50] = {0};
  strftime(buf_tm_end, 50, "%H:%M:%S", &p_tm_end);
  printf("%s\n", buf_tm);
  printf("%s\n", buf_tm_end);

  return 0;
}
