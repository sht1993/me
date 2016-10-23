#include <iostream>
using namespace std;
/*自增自减运算符（单目）的使用，++i(从右向左):先自加，返回修改后的i,i++(从左向右):先返回i，然后自加*/
class A
{
	int n;
	int d;
public:
	A(int nn,int dd):n(nn),d(dd){}
	friend ostream &operator<<(ostream &o,const A &a)
	{
		return o<<a.n<<"/"<<a.d<<endl;
	}
	A &operator ++()
	{
		n+=d;
		return *this;
	}
	friend A &operator --(A &a)//把重载写成引用以后，才能重复使用，加完一次以后，会再次引用。
	{
		a.n-=a.d;
		return a;//不能返回*this，不是成员函数
	}
	 A operator ++(int)
	{//i++,先传回旧值，在加加，把加加后的新值取代原来的值，因为要引用的化，直接返回新的值，没法返回旧址值，所以不用引用
		 A old=*this;
		n+=d;
		return old; 

	}
};
int main()
{
	A a(3,5);
	// cout<<a;
	// cout <<++ ++a;
	// cout<<a;
	// cout <<a;
	// cout <<-- --a;
	// cout <<a;
	cout <<a;
	cout <<a++;
	cout <<a;
	return 0;
}