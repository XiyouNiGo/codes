//使第一版最大区别为使用union

#include <bits/stdc++.h>

using namespace std;

class Airplane {
private:
    typedef struct AirplaneRep {
        unsigned long miles;
        char type;
    }AirplaneRep;

    //在内存池中非常常用
    union {
        AirplaneRep rep;
        Airplane *next;
    };

public:
    unsigned long getMiles() {
        return rep.miles;
    }

    char getType() {
        return rep.type;
    }

    void set(unsigned long m, char t) {
        rep.miles = m;
        rep.type = t;
    }

public:
    static void *operator new(size_t size);
    static void operator delete(void *deadObject, size_t size);

private:
    static const int BLOCK_SIZE;
    static Airplane *headOfFreeList;
};

const int Airplane::BLOCK_SIZE = 512;
Airplane *Airplane::headOfFreeList = nullptr;

void *Airplane::operator new(size_t size) {
    //防止继承时出错
    if (size != sizeof(Airplane))
        return ::operator new(size);
    Airplane *p = headOfFreeList;
    if (p)
        headOfFreeList = p->next;
    else {
        Airplane *newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        //跳过newBlock[0]
        for (int i = 1; i < BLOCK_SIZE; ++i)
            newBlock[i].next = &newBlock[i + 1];
        newBlock[BLOCK_SIZE - 1].next = nullptr;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

void Airplane::operator delete(void *deadObject, size_t size) {
    if (deadObject == nullptr) return;
    if (size != sizeof(Airplane)) {
        ::operator delete(deadObject);
        return;
    }
    //头插法
    Airplane *carcass = static_cast<Airplane*>(deadObject);
    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}

int main(int argc, char *argv[]) {
    cout << sizeof(Airplane) << endl;
    
    Airplane *arr[10];

    for (int i = 0; i < 10; ++i)
        arr[i] = new Airplane;
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << endl;
        delete arr[i];
    }

    //上下两个cookie
    for (int i = 0; i < 10; ++i)
        arr[i] = ::new Airplane;
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << endl;
        delete arr[i];
    }

    return 0;
}

