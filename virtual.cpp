/**
    Created By LZD   2017/04/09

    ��Ŀ������
        ����࣬��B1��B2ͬʱ�̳���A����࣬����Cͬʱ�̳���B1��B2��������
        ��A��Ϊ������࣬��ôC�ͻ�̳�����A�ĳ�Ա���ᵼ�¶�����
        �����A��Ϊ�������ôֻ�̳�A�ĳ�Ա

    ������һЩ˵����
        һ�������������У��ȿ�����Ϊ������ֿ�����Ϊ�������
        ������Ĺ��캯���ĳ�Ա��ʼ���б��б����г��������˹��캯���ĵ��ã���δ�г������Ĭ�Ϲ���
        ��һ����Ա��ʼ���б���ͬʱ���������ͷ������Ĺ��캯���ĵ��ã��������Ĺ��캯����ִ��
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
