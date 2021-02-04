#include <bits/stdc++.h>
#include <c++/10.2.0/ext/pool_allocator.h>

using namespace std;

size_t count_alloc;
size_t times_alloc;

void *operator new(size_t size) {
    ++times_alloc;
    count_alloc += size;
    return malloc(size);
}

void *operator new[](size_t size) {
    ++times_alloc;
    count_alloc += size;
    return malloc(size);
}

int main(int argc, char *argv[]) {
    vector<int> vec_std_alloc;
    vector<int, __gnu_cxx::__pool_alloc<int>> vec_pool_alloc;

    count_alloc = times_alloc = 0;
    for (int i = 0; i < 1000000; i++)
        vec_std_alloc.push_back(0);
    cout << "std::allocator : count_alloc = " << count_alloc
         << " times_alloc = " << times_alloc << endl;

    count_alloc = times_alloc = 0;
    for (int i = 0; i < 1000000; i++)
        vec_pool_alloc.push_back(0);
    cout << "pool_alloc : count_alloc = " << count_alloc
         << " times_alloc = " << times_alloc << endl;

    return 0;
}

