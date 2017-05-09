/**
    Created By LZD   2017/05/09
    vector相当于一个动态数组
    结合类模板的知识自定义了一个动态数组类模板
    通过运算符重载实现数组赋值、通过下标访问元素等功能
    功能函数实现改变数组大小、返回数组大小等功能
**/
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
    以下共用体和字符数组用来对出现的错误种类进行判断(ErrorType)
    从而给出输出的错误信息(errorMsg)
    ErrorType中每一个元素代表一个数作为errorMsg的下标
*/
enum ErrorType
{
    invalidArraySize,memoryAllocationError,indexOutOfRange
};
char *errorMsg[] = {"Invalid array size","Memory allocation error","Invalid index"};

template <class T>
class Array
{
private:
    T *alist;
    int size;
    void Error(ErrorType error,int badIndex = 0) const;
public:
    Array(int sz = 50);
    Array(const Array<T>& A);
    ~Array(void);
    Array<T>& operator = (const Array<T>& rhs);
    T& operator[](int);
    operator T*() const;
    int ListSize() const;
    void Resize(int sz);
};

/*
    该函数模板用来输出错误信息
*/
template <class T>
void Array<T>::Error(ErrorType error,int badIndex) const
{
    cout << errorMsg[error];
    if(error == indexOutOfRange)
        cout << badIndex;
    cout << endl;
    exit(1);
}

/*
    构造函数
    出现错误时调用输出错误信息的模板
*/
template <class T>
Array<T>::Array(int sz)
{
    if(sz <= 0)          //如果输入的要申请数组的大小<0
        Error(invalidArraySize);
    else{
        size = sz;
        alist = new T[size];
        if(alist == NULL)     //申请空间失败
            Error(memoryAllocationError);
    }
}

/*
    深拷贝函数
*/
template <class T>
Array<T>::Array(const Array<T>& X)
{
    int n = X.size;
    size = n;
    alist = new T[size];
    if(alist == NULL)
        Error(memoryAllocationError);
    T *srcptr = X.alist;          //X.alist是对象X的数组首地址
    T *destptr = alist;           //alist是本对象的数组首地址
    while(n--)                    //逐个复制
    {
        *destptr++ = *srcptr++;
    }
}

/*
    附加一个浅拷贝的例子：
    所谓浅拷贝就是将数组的首地址传过去而不是传值

    Array<int>a(10);
    Array<int>b(a);
    template <class T>
    Array<T>::Array(const Array<T>& X)
    {
        size = X.size;
        alist = X.alist;
    }
*/

/*
    析构函数
*/
template <class T>
Array<T>::~Array()
{
    delete [] alist;
}

/*
    运算符重载
    使用运算符 = 实现将一个数组赋给另一个数组的功能
*/
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs)
{
    int n = rhs.size;            //求用来赋值的数组的长度
    if(size != n)                //若与原来数组大小不同
    {
        delete [] alist;         //释放原来数组
        alist = new T[size];     //并重新申请n个大小的空间
        if(alist == NULL)        //申请失败
        {
            Error(memoryAllocationError);
        }
        size = n;
    }
    T *destptr = alist;
    T *srcptr = rhs.alist;
    while(n--)            //复制数组元素
    {
        *destptr++ = *srcptr++;
    }
    return *this;        //返回当前的对象
}

/*
    重载运算符 [] 实现下标访问数组元素
*/
template <class T>
T &Array<T>::operator [] (int n)
{
    if(n < 0 || n > size-1)         //下标越界
        Error(indexOutOfRange);
    return alist[n];
}

/*
    重载类型转换
*/
template <class T>
Array<T>::operator T*() const
{
    return alist;
}

/*
    取当前数组长度
*/
template <class T>
int Array<T>::ListSize() const
{
    return size;
}

/*
    修改数组长度
*/
template <class T>
void Array<T>::Resize(int sz)
{
    if(sz <= 0)
        Error(invalidArraySize);
    if(sz == size)
        return;
    T *newlist = new T[sz];
    if(newlist == NULL)
        Error(memoryAllocationError);
    int n = (sz <= size) ? sz : size;
    T *srcptr = alist;
    T *destptr = newlist;
    while(n--)
    {
        *destptr++ = *srcptr++;
    }
    delete [] alist;
    alist = newlist;
    size = sz;
}

int main()
{
    int i, *p;
    Array<int> a(5);
    for(i = 0;i < 5;i++)
        cin >> a[i];
    for(i = 0;i < 5;i++)
        cout << a[i] << ' ';
    cout << endl;
    Array<int> b = a;
    for(i = 0;i < 5;i++)
        cout << b[i] << ' ';
    cout << endl;
    a.Resize(10);
    for(p = a;p < a+10;p++)
        cout << *p << ' ';
    return 0;
}
