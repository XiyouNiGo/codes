#include <bits/stdc++.h>

using namespace std;

void my_handler() {
    cout << "my_handler" << endl;
    abort();
}

int main(int argc, char *argv[]) {
    set_new_handler(my_handler);
    while (1)
        new int[1000000000000000];
    return 0;
}

