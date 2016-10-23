#include <iostream>
using namespace std;

class Goods
{
	int num;//售货员货号
	int qua;//售货件数
	float price;//售货价格
	static int n;//商品销售总件数
	static double discount;//折扣
public:
	Goods(int n,int q,float p):num(n),qua(q),price(p)
	{
		cout <<"销货员"<<num<<"以每件"<<price<<"卖掉"<<qua<<"件"<<endl;
	}
	static float sum;
	void display()
	{
		cout <<"当天共销售："<<n<<"件商品，";
		cout <<"总销售款为"<<sum<<"元"<<endl;
		cout <<"每件商品的平均售价为"<<Goods::average()<<endl;
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
	// cout <<"每件商品的平均售价为："<<Goods::average()<<endl;
	return 0;
}