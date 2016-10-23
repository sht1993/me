#include <iostream>
#include <string>
/*类型转换运算符函数的小实例*/
using namespace std;

class Person
{
	string name;
	int age;
	float salary;
public:
	Person(string n,int a,float s):name(n),age(a),salary(s)
	{}
	operator double()
	{//规定返回类型不写
		return salary;
	}
	operator int()
		{//规定返回类型不写
			return age;
		}
	operator string()
	{
		return name;
	}
};
int main()
{
	Person p1("小红",18,8000);
	string info=p1;//(string)p1
	double money=p1;
	int age=p1;
	cout <<info<<money<<age<<endl;
	return 0;
}