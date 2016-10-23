#include <iostream>
#include <string>
#include "myperson.h"//包含类的头文件
/*类的成员函数，也称方法*/
using namespace std;
int thisyear;//定义一个全局变量，在小氛围内局部变量优先。
Person::Person(const string &n, bool s)//定义构造函数，用来初始化人这个对象
	{
		/*n只是引用实参里的数据，没必要复制一份，
		也没必要改动,所以用引用，且定义为常变量。如果形参和赋值的重名，
		可以用类来标注person::name=name*/
		name=n;
		year=thisyear;
		sex=s;
		lover = NULL;
	}
void Person::show()
	{
		cout <<"我是："<<name<<",今年是"<<thisyear-year<<"岁,"<<(sex?"上海滩扛把子":"夜上海一枝花")<<",";
		if (lover)
			cout <<"就人群中看了"<<lover->name<<"一眼就爱上了他"<<endl;
		else
			cout <<"单身"<<endl;

	}
void Person::love(Person &p1)//这里的形参per1是否可以不写，这里是直接引用实参
{
	//this指向调用该成员函数的对象。其中当前对象的首地址传递给this
	lover=&p1;//等价于per2.lover=&p1=(*this).lover=&p1;per2=*this;
	p1.lover=this;//把per2地址（也就是this）传递给实参的lover指针；
}