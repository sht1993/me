#include <iostream>
using namespace std;

class Goods
{
	int num;//�ۻ�Ա����
	int qua;//�ۻ�����
	float price;//�ۻ��۸�
	static int n;//��Ʒ�����ܼ���
	static double discount;//�ۿ�
public:
	Goods(int n,int q,float p):num(n),qua(q),price(p)
	{
		cout <<"����Ա"<<num<<"��ÿ��"<<price<<"����"<<qua<<"��"<<endl;
	}
	static float sum;
	void display()
	{
		cout <<"���칲���ۣ�"<<n<<"����Ʒ��";
		cout <<"�����ۿ�Ϊ"<<sum<<"Ԫ"<<endl;
		cout <<"ÿ����Ʒ��ƽ���ۼ�Ϊ"<<Goods::average()<<endl;
	}
	float total()
	{
		if(qua<0) throw qua;
		else
		{
			if(qua>10)sum+=qua*price*discount;
			else sum+=qua*price;
		}
		n+=qua;

	}
	static float average();
};
double Goods::discount=0.98;
int Goods::n=0;
float Goods::sum=0;
float Goods::average()
{
	return (sum/n);
}
int main()
{
	Goods goods[3]={
		Goods(101,5,23.5),
		Goods(102,12,24.56),
		Goods(103,100,21.5)
	};
	for(int i=0;i<3;i++)
		goods[i].total();
	goods[1].display();
	// cout <<"ÿ����Ʒ��ƽ���ۼ�Ϊ��"<<Goods::average()<<endl;
	return 0;
}