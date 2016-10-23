#include <iostream>
using namespace std;
/*使用引用实现变量值的互换；其中main函数在调用swep函数的时候,
完成了实参向形参的传递，形参为实参的引用，即形参的值和实参相同
改变引用的值，实参值也会随之改变*/
void swap(int &a,int &b)
{
	int temp=0;
	cout <<"形参刚接到实参传来的值："<<endl<<"a="<<a<<endl<<"b="<<b<<endl;
	temp=a;
	a=b;
	b=temp;
	cout <<"转换后形参的值："<<endl<<"a="<<a<<endl<<"b="<<b<<endl;
}

int main()
{
	int i=1,j=100;
	swap(i,j);
	cout <<"变量值互换后："<<endl<<"i="<<i<<endl<<"j="<<j<<endl;
	return 0;
}