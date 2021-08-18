#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

/* non-blocking connect */
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8000
#define SEND_DATA "helloworld"

int main(int argc, char* argv[]) {
  int clientfd = socket(AF_INET, SOCK_STREAM, 0);
  if (clientfd == -1) {
    std::cout << "create client socket error." << std::endl;
    return -1;
  }

  int oldSocketFlag = fcntl(clientfd, F_GETFL, 0);
  int newSocketFlag = oldSocketFlag | O_NONBLOCK;
  if (fcntl(clientfd, F_SETFL, newSocketFlag) == -1) {
    close(clientfd);
    std::cout << "set socket to nonblock error." << std::endl;
    return -1;
  }

  struct sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
  serveraddr.sin_port = htons(SERVER_PORT);
  for (;;) {
    int ret =
        connect(clientfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (ret == 0) {
      std::cout << "connect to server successfully." << std::endl;
      close(clientfd);
      return 0;
    } else if (ret == -1) {
      if (errno == EINTR) {
        std::cout << "connecting interruptted by signal, try again."
                  << std::endl;
        continue;
      } else if (errno == EINPROGRESS) {
        /* in progress */
        break;
      } else {
        close(clientfd);
        return -1;
      }
    }
  }

  fd_set writeset;
  FD_ZERO(&writeset);
  FD_SET(clientfd, &writeset);
  struct timeval tv;
  tv.tv_sec = 3;
  tv.tv_usec = 0;
  if (select(clientfd + 1, NULL, &writeset, NULL, &tv) != 1) {
    std::cout << "[select] connect to server error." << std::endl;
    close(clientfd);
    return -1;
  }

  int err;
  socklen_t len = static_cast<socklen_t>(sizeof err);
  /* getsockopt to determine whether connect was called successfully */
  if (::getsockopt(clientfd, SOL_SOCKET, SO_ERROR, &err, &len) < 0) {
    close(clientfd);
    return -1;
  }

  if (err == 0)
    std::cout << "connect to server successfully." << std::endl;
  else
    std::cout << "connect to server error." << std::endl;

  close(clientfd);

  return 0;
}