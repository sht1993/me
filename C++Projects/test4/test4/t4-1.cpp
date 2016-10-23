#include <iostream>
#include <string>
using namespace std;
/*定义一个程序员类，数据成员有姓名，性别
（学号、成绩），老师（教室），函数成员有报名、
听课、换老师（教室）。在主函数里定义两个对象报名、听课换老师、在听课*/ 
class Student
{
public:
	Student::Student(const string &n,char s):name(n),sex(s){ }
	void study();
	static void changeTeacher(const string &t);
private:
	string name;
	char sex;
	static string teacher;//静态成员函数

};
string Student::teacher="谭浩";
void Student::study(){cout <<name<<"参加大数据培训班;"<<"在听"<<teacher<<"讲课;"<<endl;}
void Student::changeTeacher(const string &t)//类外定义静态成员函数
{
	teacher = t;
}
int main()
{
	Student stud1("肖奈",'m'); 
	Student stud2("微微",'f'); 
	stud1.study();
	stud2.study();
	Student::changeTeacher("李老师");//静态成员函数
	return 0;
}