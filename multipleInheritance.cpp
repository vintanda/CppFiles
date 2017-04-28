/**
    Created By LZD   2017/04/09

    题目描述：
        多重继承练习
        Derive继承Base1 Base2 Base3
        了解构造函数的调用
**/

#include<iostream>
using namespace std;

class Base1 {
	private:
	int b1;
	public:
	Base1() {
		b1 = 0;
		cout << "MoRenGouZaoFunctionBase1:" << "b1 = " << b1 << endl;
	}
	Base1(int i) {
		b1 = i;
		cout << "GouZaoFunctionBase1:" << "b1 = " << b1 << endl;
	}
};

class Base2 {
	private:
	int b2;
	public:
	Base2() {
		b2 = 0;
		cout << "MoRenGouZaoFunctionBase2:" << "b2 = " << b2 << endl;
	}
	Base2(int j) {
		b2 = j;
		cout << "GouZaoFunctionBase2:" << "b2 = " << b2 << endl;
	}
};

class Base3 {
	public:
	Base3() {
		cout << "MoRenGouZaoFunctionBase3." << endl;
	}
};

class Derive : public Base1,public Base2,public Base3 {
	private:
	Base1 memberBase1;
	Base2 memberBase2;
	Base3 memberBase3;
	public:
	Derive() {
		cout << "MoRenGouZaoFunctionDerive." << endl;
	}
	Derive(int a,int b,int c,int d):Base1(a),Base2(b),memberBase1(c),memberBase2(d) {
		cout << "GouZaoFunctionDerive." << endl;
	}
};

int main() {
	cout << "\nnew son class duixiang obj1:" << endl;
	Derive obj1;
	cout << "\nnew son class duixiang obj2(1,2,3,4):" << endl;
	Derive obj2(1,2,3,4);
	return 0;
}
