#include <iostream>
/*匿名对象用法*/
using namespace std;
class Fen{
		int m;//分子 
		int n;// 分母
	public:
		Fen(int m,int n=1):m(m),n(n){
			cout<<"Fen("<<m<<"/"<<n<<")"<<endl;
		}
		~Fen()
		{
			cout<<" free Fen("<<m<<"/"<<n<<")"<<endl;
		}

		Fen add(const Fen &f1)//分数加法运算后，依然是分数。类型为类。
		{
			int mn=n*f1.n;
			int mm=n*f1.m+m*f1.n;
			// Fen result(mm,mn);
			// return result;
			return Fen (mm,mn);//由于result只用一次，所以直接用匿名对象。
		}
		Fen multipiy(const Fen &f1)
		{
			return Fen(m*f1.m,n*f1.n);
		}
		void show()
		{
			cout <<m<<"/"<<n<<endl;
		}
};
int main()
{
	Fen f1(2,5);
	Fen f2(3,5);
	cout <<"--------------"<<endl;
	f2.add(f1).show();
	cout <<"--------------"<<endl;
	f1.add(Fen(1,5)).show();
	cout <<"--------------"<<endl;
	f1.add((2,5)).show();
	cout <<"--------------"<<endl;
	f1.add(2).show();//通过匿名对象自动类型转换为fen（2）
	cout <<"--------------"<<endl;
	f2.multipiy(f1).show();
	cout <<"--------------"<<endl;
	return 0;
}