/**
    Created By LZD   2017/04/09

    题目描述：
        CircleTable 继承 Circle 和 Table
		是多重继承的一个实例
**/
#include<iostream>
using namespace std;

enum Color {Red,Yellow,Green,White};
class Circle {
private:
    float radius;
public:
    Circle(float r) {
        radius = r;
        cout << "Circle!" << endl;
    }
    ~Circle() {
        cout << "Circle Destory!" << endl;
    }
    float getArea() {
    return 3.14 * radius * radius;
    }
};

class Table {
private:
    float height;
public:
    Table(float h) {
        height = h;
        cout << "Table!" << endl;
    }
    ~Table() {
        cout << "Table Destory!" << endl;
    }
    float getHeight() {
        return height;
    }
};

class RoundTable:public Circle,public Table {
private:
    Color color;
public:
    RoundTable(float h,float r,Color c);
    int getColor() {
        return color;
    }
    ~RoundTable() {
        cout << "RoundTable Destory!" << endl;
    }
};

RoundTable::RoundTable(float h,float r,Color c):Table(h),Circle(r) {
    color = c;
    cout << "RoundTable!" << endl;
}

int main() {
    RoundTable cir_table(15.0,2.0,Green);
    cout << "The table properties are:" << endl;
    cout << "height = " << cir_table.getHeight() << endl;
    cout << "area = " << cir_table.getArea() << endl;
    cout << "color = " << cir_table.getColor() << endl;
    return 0;
}
