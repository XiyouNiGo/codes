#include <bits/stdc++.h>

using namespace std;

class Foo {
public:
    int _id;
    long _data;
    string _str;

public:
    Foo() : _id(0) {
        cout << "default ctor. this = " << this << " id = " << _id << endl;
    }

    Foo(int i) : _id(i) {
        cout << "ctor. this = " << this << " id = " << _id << endl;
    }

    virtual
    ~Foo() {
        cout << "dtor. this = " << this << " id = " << _id << endl;
    }

    //重载new编译器自动加上static
    //在重载new中调用new会造成无限循环
    //第一参数必须是size_t
    static void *operator new(size_t size);
    static void operator delete(void *pdead, size_t size);
    static void *operator new[](size_t size);
    static void operator delete[](void *pdead, size_t size);
};

void *Foo::operator new(size_t size) {
    cout << "void *Foo::operator new(size_t size)" << endl;
    return malloc(size);
}

void *Foo::operator new[](size_t size) {
    cout << "void *Foo::operator new[](size_t size)" << endl;
    return malloc(size);
}

void Foo::operator delete(void *pdead, size_t size) {
    cout << "void operator delete(void *pdead, size_t size)" <<endl;
    free(pdead);
}

void Foo::operator delete[](void *pdead, size_t size) {
    cout << "void operator delete[](void *pdead, size_t size)" <<endl;
    free(pdead);
}

int main(int argc, char *argv[]) {
    cout << "sizeof(Foo) = " << sizeof(Foo) << endl;
    Foo *p = new Foo(5);
    delete p;

    Foo *pArray = new Foo[5];
    delete[] pArray;
    return 0;
}

