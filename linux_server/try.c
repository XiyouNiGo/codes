#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
    printf("%d\n", EAGAIN == EWOULDBLOCK);
    return 0;
}

