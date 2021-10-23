/*
 * @Author: NiGo
 * @LastEditors: NiGo
 * @Date: 2021-10-23 12:05:07
 * @LastEditTime: 2021-10-23 12:07:44
 * @Description: file content
 * @FilePath: /linux_server/evenfd_semaphore.cpp
 */
#include <bits/stdc++.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/eventfd.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdlib>
#include <iterator>

#define my_err(msg)     \
  do {                  \
    perror(msg);        \
    exit(EXIT_FAILURE); \
  } while (0)

using namespace std;

int main(int argc, char *argv[]) {
  int efd = 0;
  // 要求是8字节
  size_t count = 0;
  pid_t nret = 0;
  // create a file descriptor for event notification
  // 用于异步唤醒
  if ((efd = eventfd(0, EFD_SEMAPHORE)) == -1) {
    my_err("evenfd error");
  }
  if ((nret = fork()) == 0) {
    for (size_t i = 0; i < 5; i++) {
      // 尝试加到count上
      write(efd, &i, sizeof(i));
      cout << "Child write " << i << endl;
    }
  } else if (nret > 0) {
    sleep(1);
    // 成功时read永远返回1
    read(efd, &count, sizeof(count));
    cout << "Parent read " << count << endl;
    // read again
    read(efd, &count, sizeof(count));
    cout << "Parent read " << count << endl;
  } else {
    my_err("fork error");
  }
  return 0;
}