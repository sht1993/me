#include <iostream>
/*���������÷�*/
using namespace std;
class Fen{
		int m;//���� 
		int n;// ��ĸ
	public:
		Fen(int m,int n=1):m(m),n(n){
			cout<<"Fen("<<m<<"/"<<n<<")"<<endl;
		}
		~Fen()
		{
			cout<<" free Fen("<<m<<"/"<<n<<")"<<endl;
		}

		Fen add(const Fen &f1)//�����ӷ��������Ȼ�Ƿ���������Ϊ�ࡣ
		{
			int mn=n*f1.n;
			int mm=n*f1.m+m*f1.n;
			// Fen result(mm,mn);
			// return result;
			return Fen (mm,mn);//����resultֻ��һ�Σ�����ֱ������������
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
	f1.add(2).show();//ͨ�����������Զ�����ת��Ϊfen��2��
	cout <<"--------------"<<endl;
	f2.multipiy(f1).show();
	cout <<"--------------"<<endl;
	return 0;
}