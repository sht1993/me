#ifndef _MY_PERSON_H
#define _MY_PERSON_H
#include <iostream>
#include <string>
using namespace std;
extern int thisyear;
/*声明一个全局变量；会用static、const、extern声明全局变量
，其中在多文件编程中，定义全局变量，一般要在.h头文件中声明，
之后在.cpp文件中定义，才能使用，定义一般放在函数的方法定义之前
，多文件编程，为达到信息隐蔽，一般把类封装为.h头文件，
其方法一般放在.cpp中，主函数只用来执行，放置对象调用函数的接口
这样保护数据，把内部程序核心封装成黑盒*/
class Person
{
		string name;
		int year;
		bool sex;
		Person *lover;//把爱人可以定义为指针
	public:
		Person(const string &n, bool s);//定义构造函数，用来初始化人这个对象
		void show();
		void love(Person &p1);
};
#endif