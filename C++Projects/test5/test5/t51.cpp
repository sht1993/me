#include <iostream>
using namespace std;
/*�����Լ����������Ŀ����ʹ�ã�++i(��������):���Լӣ������޸ĺ��i,i++(��������):�ȷ���i��Ȼ���Լ�*/
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
	friend A &operator --(A &a)//������д�������Ժ󣬲����ظ�ʹ�ã�����һ���Ժ󣬻��ٴ����á�
	{
		a.n-=a.d;
		return a;//���ܷ���*this�����ǳ�Ա����
	}
	 A operator ++(int)
	{//i++,�ȴ��ؾ�ֵ���ڼӼӣ��ѼӼӺ����ֵȡ��ԭ����ֵ����ΪҪ���õĻ���ֱ�ӷ����µ�ֵ��û�����ؾ�ֵַ�����Բ�������
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