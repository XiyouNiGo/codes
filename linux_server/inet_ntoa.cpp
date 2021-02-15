#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char *argv[]) {
    struct in_addr addr1, addr2;
    if (INADDR_NONE == inet_aton("1.2.3.4", &addr1))
        return -1;
    if (INADDR_NONE == inet_aton("10.194.71.60", &addr2))
        return -1;

    //函数的返回值指向静态内存
    //inet_ntoa是不可重入的
    char *szValue1 = inet_ntoa(addr1);
    char *szValue2 = inet_ntoa(addr2);
    printf("address 1: %s\n", szValue1);
    printf("address 2: %s\n", szValue2);

    return 0;
}

