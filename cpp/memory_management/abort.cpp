#include <bits/stdc++.h>

using namespace std;

class A {
public:
    A(string i) : identy(i) {  }

    string get_identy() {
        return identy;
    }

    ~A() {
        cout << identy << endl;
    }
private:
    string identy;
};

// abort会发送SIGABORT信号
//调用exit后，程序会调用静态对象和全局对象的析构函数
//但abor什么析构函数都不会调用。
//程序完全退出时，系统会释放所有未释放的内存和和其他资源

A go("global object");

int main(int argc, char *argv[]) {
    A lo("local object");
    static A slo("static local object");
    //abort();
    exit(0);
    //return 0;
}

