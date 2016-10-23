#include <iostream>
using namespace std;
#include <string>
class Person
{
	string name;
public:
	Person(const char *n):name(n)
	{
		cout <<"Person:"<<n<<endl;
	}
	~Person()
	{
		cout <<"free Person()"<<endl;
	}
	void show()
	{
		cout <<"我是:"<<name<<endl;
	}
	const string &getName(){return name;}//由于派生类不能直接调用父类的私有成员，所以用get函数来返回私有成员，希望返回的不改变，不复制。
};
class Teacher:public Person
{
	string course;
public:
	Teacher(const char *n,const char *c):course(c),Person(n)
	{
		cout <<"Teacher:"<<n<<"教授"<<c<<endl;
	}
	~Teacher()
	{
		cout <<"free Teacher"<<endl;
	}
	void show(const char *m)
	{
		cout <<m<<"班，我是："<<course<<"课程老师"<<getName()<<endl;
	}
};
int main()
{
	Person b("小红");
	Teacher a("小明","C++");
	a.show("18");
	b.show();
	return 0;
}