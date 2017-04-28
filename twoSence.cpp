/**
    Created By LZD   2017/04/09

    题目描述：
        多重继承的二义性
**/
#include<iostream>
using namespace std;

class A {
public:
    void fun() {    cout << "a.fun()" << endl;  }
};

class B {
public:
    void fun() {    cout << "b.fun()" << endl;  }
    void gun() {    cout << "b.gun()" << endl;  }
};

class C : public A, public B {
public:
    void gun() {    cout << "c.gun()" << endl;  }
    void hun() {    A::fun();  }            // void hun() { fun(); } 二义性
};

int main() {
    C c , *p = &c;

    cout << "\nc:" << endl;
    c.A::fun();
    c.B::fun();
    c.gun();
    c.hun();

    cout << "\np:" << endl;
    p->A::fun();
    p->B::fun();
    p->gun();
    p->hun();

    return 0;
}
