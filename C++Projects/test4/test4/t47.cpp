#include <iostream>
using namespace std;
/*����������������*/
class Fen
{
	int n;
	int d;//��ĸ
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
	/*��Ԫ���������������������������*/
	o <<f.n<<"/"<<f.d;
	return o;
	// operator<<(o,x.n)==>operator(ostram&,int)
}
istream &operator >>(istream &io,Fen &f)
{
	char c;
	int n,d;
	io >>n>>c>>d;
	f=Fen (n,d);//��Ϊ�����Լ�֣����ù��캯������ʱӦ���� ����������
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