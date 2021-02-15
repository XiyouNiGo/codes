#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char *argv[]) {
    struct in_addr addr;
    if (0 == inet_pton(AF_INET, "127.0.0.1", &addr))
        return -1;

    char dst[INET_ADDRSTRLEN];
    printf("%s\n", inet_ntop(AF_INET, &addr, dst, INET_ADDRSTRLEN));
    return 0;
}

