#include <bits/stdc++.h>

using namespace std;

class A {
public:
    int id;

    A() : id(0) {
        cout << "default ctor. this = " << this << " id = " << id << endl;
    }
    
    A(int i) : id(i) {
        cout << "ctor. this = " << this << " id = " << id << endl;
    }

    ~A() {
        cout << "dtor. this = " << this << " id = " << id << endl;
    }

    void *operator new(size_t size, int i, char ch) {
        cout << "call void *operator new(" << size << ", " << i << ", " << ch << ")" << endl;
        return malloc(size);
    }

    //new operator时
    //构造函数出错时使用
    void operator delete(void *pdead, int i, char ch) {
        cout << "call void *operator delete(" << pdead << ", " << i << ", " << ch << ")" << endl;
        free(pdead);
    }
};

int main(int argc, char *argv[]) {
    A *buf = new A[3];
    A *tmp = buf;
    cout << "buf = " << buf << " tmp = " << tmp << endl;
    for (int i = 0; i < 3; i++) 
        ::new(tmp++) A(i);
    cout << "buf = " << buf << " tmp = " << tmp << endl;
    //构造从上往下
    //析构从下往上
    delete[] buf;

    //placement new底层调用operator new
    A *buf2 = new(100, 'A') A;
    ::delete buf2;
    return 0;
}

