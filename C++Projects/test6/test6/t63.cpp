#include <iostream>
using namespace std;
#include <string>
/*多重继承，与虚基类的使用*/
class Person
{
	string name;
public:
	Person(const char *a):name(a)
	{
		cout <<"Person("<<a<<");"<<endl;
	}
	const string &setname()const{return name;}
};
class Teacher:virtual public Person
{
	string cour;
public:
	Teacher(const char *n,const char *c):cour(c),Person(n)
	{
		cout <<"Teacher:"<<n<<"讲"<<c<<endl;
	}
	void teach(const char *b)
	{
		cout <<setname()<<"老师带"<<b<<"班,讲"<<cour<<endl;
	}

};
class Student:virtual public Person
{
	string sid;
public:
	Student(const char*n,const char*id):sid(id),Person(n)
	{
		cout <<"Student:"<<n<<"学号："<<sid<<endl;
	}
	void study(const char *room)
	{
		cout <<setname()<<"学生在"<<room<<"上课"<<endl;
	}
};
class Shuo:public Teacher,public Student
{
public:
	Shuo(const char*n,const char*c,const char *id):Teacher(n,c),Student(n,id),Person(n)
	{
		cout <<"一个硕士"<<n<<"讲"<<c<<"学号"<<id<<endl;
	}
};
int main()
{
	Shuo s("权哥","c++","2015020");
	s.teach("205");
	s.study("123");
	cout <<s.setname()<<endl;
	return 0;
}