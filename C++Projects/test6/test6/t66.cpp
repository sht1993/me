#include <iostream>
/*纯虚函数体验程序*/
using namespace std;
class Vicale
{
public:
	virtual void stop()=0;/*stop函数作为父类的虚函数，定义的函数体没有必要显示，所以可以声明为纯虚函数。*/
	/*{//虚函数，使函数调用时，可以识别对象的不同响应。
		// cout <<"Vicale停车"<<endl;
	}*/
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
	static void stopVicale(Vicale& v)
	{
		v.stop();
	}
};
int main(int argc, char const *argv[])
{
	// Light l;
	Car bmw;
	Bike jnt;
	cout <<sizeof(Vicale)<<endl;//有无virtual测试，看虚函数列表。
	Light::stopVicale(bmw);
	Light::stopVicale(jnt);
	 //Vicale v;抽象类不能实例化对象。'Vicale' : cannot instantiate abstract class
	return 0;
}