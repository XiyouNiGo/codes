#include <bits/stdc++.h>

using namespace std;

//memmove保证结果正确
//memset速度更快

void *my_memcpy(void *dst, const void *src, size_t n) {
    char *tmp = (char*)dst;
    char *s_src = (char*)src;
    while(n--) {
        *tmp++ = *s_src++;
    }
    return dst;
}

void* my_memmove(void* dst, const void* src, size_t n) {
    char* s_dst;
    char* s_src;
    s_dst = (char*)dst;
    s_src = (char*)src;
    if(s_dst>s_src && (s_src+n>s_dst)) {
        s_dst = s_dst+n-1;
        s_src = s_src+n-1;
        while(n--) {
            *s_dst-- = *s_src--;
        }
    } else {
        while(n--) {
            *s_dst++ = *s_src++;
        }
    }
    return dst;
}

int main(int argc, char *argv[]) {
    cout << "Hello world" << endl;
    return 0;
}

