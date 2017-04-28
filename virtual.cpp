/**
    Created By LZD   2017/04/09

    题目描述：
        虚基类，当B1和B2同时继承了A这个类，并且C同时继承了B1和B2这两个雷
        若A作为非虚基类，那么C就会继承两份A的成员，会导致二义性
        但如果A作为虚基类那么只继承A的成员

    虚基类的一些说明：
        一个类在在类族中，既可以作为虚基类又可以作为非虚基类
        派生类的构造函数的成员初始化列表中必须列出对续集了构造函数的调用，若未列出则调用默认构造
        若一个成员初始化列表中同时出现虚基类和非虚基类的构造函数的调用，则虚基类的构造函数先执行
**/

#include<iostream>
using namespace std;

class A {
private:
    int nv;
public:
    A(int n) {
        nv = n;
        cout << "Member of A" << endl;
    }
    void fun() {
        cout << "fun of A" << endl;
    }
};

class B1 : virtual public A {
private:
    int nv1;
public:
    B1(int a) : A(a) {
        cout << "Member of B1" << endl;
    }
};

class B2 : virtual public A {
private:
    int nv2;
public:
    B2(int a) : A(a) {
        cout << "Member of B2" << endl;
    }
};

class C : public B1, public B2 {
private:
    int nvd;
public:
    C(int a) : A(a),B1(a),B2(a) {
        cout << "Member of C" << endl;
    }
    void fund() {
    cout << "fun of C" << endl;
    }
};

int main() {
    C c1(1);
    c1.fund();
    c1.fun();
    return 0;
}
