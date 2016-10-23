#include <iostream>
using namespace std;
#include <typeinfo>
/*dynamic_cast,和typeid 类转换应用*/

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
class RedCar:public Car
{
public:
	void stop()
	{
		cout <<"红轿车离合刹车"<<endl;
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
class computor
{
public:
	void show()
	{
		cout <<"this is computor"<<endl;
	}
};
class macComputor:public computor
{
	public:
		void show()
		{
			cout <<"this is mac"<<endl;
		}
};
class changeOk
{
public:
	void test(Vicale* v)
	{
		Car* c=dynamic_cast<Car*>(v);
		if(c) cout<<"是小轿车"<<endl;
		RedCar* rc=dynamic_cast<RedCar*>(v);
		if(rc) cout<<"是红色小轿车"<<endl;
		Bike* b=dynamic_cast<Bike*>(v);
		if(b) cout<<"是自行车"<<endl;
	}

};
int main(int argc, char const *argv[])
{
	computor *c1=new macComputor();
	//dynamic_cast <macComputor*>(c);// 'dynamic_cast' : 'computor' is not a polymorphic type
	Vicale* c=new Car();
	Vicale* rc=new RedCar();
	Vicale* b=new Bike();
	changeOk ck;
	ck.test(c);
	ck.test(rc);
	ck.test(b);
	cout <<typeid(rc).name()<<"--"<<typeid(*rc).name()<<"--"<<typeid(ck).name()<<endl;
	cout <<boolalpha<<(typeid(*rc)==typeid(RedCar))<<endl;//boolalpha把1，0显示ture false.
	return 0;
}