#include <iostream>
/*体会虚函数用法，理解调用过程*/
using namespace std;
class Vicale
{
public:
	 virtual void stop()
	{//虚函数，使函数调用时，可以识别对象的不同响应。
		cout <<"Vicale停车"<<endl;
	}
};
class Car:public Vicale
{
public:
	void stop()
	{
		cout <<"轿车离合刹车"<<endl;
	}
};
class Bike:public Vicale
{
public:
	void stop()
	{
		cout <<"自行车手刹刹车"<<endl;
	}
};
class Light
{
public:
	void stopVicale(Vicale &v)
	{
		v.stop();
	}
};
int main(int argc, char const *argv[])
{
	Light l;
	Car bmw;
	Bike jnt;
	cout <<sizeof(Vicale)<<endl;//有无virtual测试，看虚函数列表。
	l.stopVicale(bmw);
	l.stopVicale(jnt);
	return 0;
}