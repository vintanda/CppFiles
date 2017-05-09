/**
    Created By LZD   2017/05/09
    vector�൱��һ����̬����
    �����ģ���֪ʶ�Զ�����һ����̬������ģ��
    ͨ�����������ʵ�����鸳ֵ��ͨ���±����Ԫ�صȹ���
    ���ܺ���ʵ�ָı������С�����������С�ȹ���
**/
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
    ���¹�������ַ����������Գ��ֵĴ�����������ж�(ErrorType)
    �Ӷ���������Ĵ�����Ϣ(errorMsg)
    ErrorType��ÿһ��Ԫ�ش���һ������ΪerrorMsg���±�
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
    �ú���ģ���������������Ϣ
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
    ���캯��
    ���ִ���ʱ�������������Ϣ��ģ��
*/
template <class T>
Array<T>::Array(int sz)
{
    if(sz <= 0)          //��������Ҫ��������Ĵ�С<0
        Error(invalidArraySize);
    else{
        size = sz;
        alist = new T[size];
        if(alist == NULL)     //����ռ�ʧ��
            Error(memoryAllocationError);
    }
}

/*
    �������
*/
template <class T>
Array<T>::Array(const Array<T>& X)
{
    int n = X.size;
    size = n;
    alist = new T[size];
    if(alist == NULL)
        Error(memoryAllocationError);
    T *srcptr = X.alist;          //X.alist�Ƕ���X�������׵�ַ
    T *destptr = alist;           //alist�Ǳ�����������׵�ַ
    while(n--)                    //�������
    {
        *destptr++ = *srcptr++;
    }
}

/*
    ����һ��ǳ���������ӣ�
    ��νǳ�������ǽ�������׵�ַ����ȥ�����Ǵ�ֵ

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
    ��������
*/
template <class T>
Array<T>::~Array()
{
    delete [] alist;
}

/*
    ���������
    ʹ������� = ʵ�ֽ�һ�����鸳����һ������Ĺ���
*/
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs)
{
    int n = rhs.size;            //��������ֵ������ĳ���
    if(size != n)                //����ԭ�������С��ͬ
    {
        delete [] alist;         //�ͷ�ԭ������
        alist = new T[size];     //����������n����С�Ŀռ�
        if(alist == NULL)        //����ʧ��
        {
            Error(memoryAllocationError);
        }
        size = n;
    }
    T *destptr = alist;
    T *srcptr = rhs.alist;
    while(n--)            //��������Ԫ��
    {
        *destptr++ = *srcptr++;
    }
    return *this;        //���ص�ǰ�Ķ���
}

/*
    ��������� [] ʵ���±��������Ԫ��
*/
template <class T>
T &Array<T>::operator [] (int n)
{
    if(n < 0 || n > size-1)         //�±�Խ��
        Error(indexOutOfRange);
    return alist[n];
}

/*
    ��������ת��
*/
template <class T>
Array<T>::operator T*() const
{
    return alist;
}

/*
    ȡ��ǰ���鳤��
*/
template <class T>
int Array<T>::ListSize() const
{
    return size;
}

/*
    �޸����鳤��
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
