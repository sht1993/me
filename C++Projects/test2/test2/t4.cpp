#include <iostream>
using namespace std;
/*ʹ������ʵ�ֱ���ֵ�Ļ���������main�����ڵ���swep������ʱ��,
�����ʵ�����βεĴ��ݣ��β�Ϊʵ�ε����ã����βε�ֵ��ʵ����ͬ
�ı����õ�ֵ��ʵ��ֵҲ����֮�ı�*/
void swap(int &a,int &b)
{
	int temp=0;
	cout <<"�βθսӵ�ʵ�δ�����ֵ��"<<endl<<"a="<<a<<endl<<"b="<<b<<endl;
	temp=a;
	a=b;
	b=temp;
	cout <<"ת�����βε�ֵ��"<<endl<<"a="<<a<<endl<<"b="<<b<<endl;
}

int main()
{
	int i=1,j=100;
	swap(i,j);
	cout <<"����ֵ������"<<endl<<"i="<<i<<endl<<"j="<<j<<endl;
	return 0;
}