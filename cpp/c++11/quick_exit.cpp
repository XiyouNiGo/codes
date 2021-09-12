#include <bits/stdc++.h>

class Foo {
public:
    ~Foo() {
        std::cout << "Foo dtor func" << std::endl;
    }
};

void quick_exit_func() {
    std::cout << "quick_exit_func" << std::endl;
}

int main(int argc, char *argv[]) {
    Foo foo;
    at_quick_exit(quick_exit_func);
    quick_exit(0);
    /* return 0; */
}

