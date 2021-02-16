#include <bits/stdc++.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h>
#include <fcntl.h>

using namespace std;

int setnoblocking(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

int main(int argc, char *argv[]) {
    printf("%d", argc);
    //assert(argc != 2);
    int fd = atoi(argv[1]);
    setnoblocking(fd);
    return 0;
}

