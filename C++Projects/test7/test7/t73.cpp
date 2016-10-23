#include <iostream>
using namespace std;
#include <exception>
#include <new>
#include <cstdio>
class A
{
	int* p;
	int len;
public:
	explicit A(int n)
	{
		p=new (nothrow) int[n];
		len=n;
	}
	int& operator[] (int index)//下表运算符重载，用[index]数组中元素
	{
		if(index<0) throw NegIndex(index); //判断越界
		if(index>=len) throw OutRange(index);
		if(p==NULL) throw MemoryException();
		return p[index];
	}
class NegIndex:public exception
{
	int i;
public:
	NegIndex(int index)throw():i(index){}
	const char* what() const throw()
	{
		static char buf[100];
		sprintf(buf,"负下标异常%d",i);
		return buf;
	}
};
class OutRange:public exception
{
	int i;
public:
	OutRange(int index)throw():i(index){}
	const char* what() const throw()
	{
		static char buf[100];
		sprintf(buf,"下标越界异常%d",i);
		return buf;
	}
};
class MemoryException:public exception
{
	public:
	const char* what() const throw()
	{
		return "内存不足";
	}	
};
};
int main(int argc, char const *argv[])
{
	A x(10);
	x[0]=10;x[3]=5;x[8]=3;
	cout <<x[0]*x[3]*x[8]<<endl;
	//cout <<x[-3]<<endl;
	cout <<x[15]<<endl;
	return 0;
}