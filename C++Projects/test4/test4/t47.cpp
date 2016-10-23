#include <iostream>
using namespace std;
/*运算符重载体验程序*/
class Fen
{
	int n;
	int d;//分母
public:
	Fen(int nn,int dd=1):n(nn),d(dd)
	{
		if(d<0)n=-n,d=-d;
		for(int i=d;i>1;i--)
		{
			if(d%i==0&&n%i==0)
			{
				d/=i,n/=i;
				break;
			}
		}
	}
	friend ostream &operator << (ostream &o,const Fen &f);
	friend istream &operator >> (istream &io,Fen &f);
	friend Fen &operator + (const Fen &r1,const Fen &r2);
};

ostream &operator << (ostream &o,const Fen &f)
{
	/*友元函数，在类中声明，运算符重载*/
	o <<f.n<<"/"<<f.d;
	return o;
	// operator<<(o,x.n)==>operator(ostram&,int)
}
istream &operator >>(istream &io,Fen &f)
{
	char c;
	int n,d;
	io >>n>>c>>d;
	f=Fen (n,d);//因为输入后不约分，调用构造函数，这时应用了 匿名函数。
	return io;
}
Fen &operator + (const Fen &r1,const Fen &r2)
{
	int nd=r1.d*r2.d;
	int nn=r1.n*r2.d+r1.d*r2.n;
	return Fen (nn,nd);
}
int main()
{
	Fen f1(6,8),f2(8,12);
	cout <<f1<<"   "<<f2<<endl;////operator<<(cout,f1)
	// cin >>f1;
	// cout <<f1<<endl;
	cout <<f1+f2<<endl;

	return 0;
}