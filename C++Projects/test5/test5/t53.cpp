#include <iostream>
using namespace std;
/*�����������������Բ���ź���Ӧ�ã�ֻ�ܶ���Ϊ���Ա����*/
class Array
{ 
	int *p;//������
	int len;//���鳤�ȣ�Ԫ�ظ�����
public: 
	//��Ĭ��ֵ�Ĺ��캯��,ָ�����鳤�ȣ���Ҫ�����鸳ֵ
	Array(int n=10,int value=int()):p(new int[n]),len(n)
	{
		for(int i=0;i<len;i++) p[i]=value;
	}
	void operator ()(int start,int step)//���أ����������������
	{
		for(int i=0;i<len;i++)
		{
			p[i]=start+i*step;
		}
	}
	int operator ()()//
	{
		int sum=0;
		for(int i=0;i<len;i++)
		{
			sum+=p[i];
		}
		return sum;
	}
	friend ostream &operator << (ostream &o,Array &a1)//����<<ʵ���������������Ԫ��
	{
		for(int i=0;i<a1.len-1;i++)
		o <<a1.p[i]<<",";
		o <<a1.p[a1.len-1];
		return o;
	}
};
int main()
{
	Array a1;
	a1(5,1);//��5��ʼ���ղ���Ϊ1,��䣻a.operator() (5,1)
	cout <<a1<<endl;
	cout <<a1()<<endl;

	return 0;
}