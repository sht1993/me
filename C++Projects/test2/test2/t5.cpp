#include <iostream>
#include <string>
/*把一组含有学生姓名和成绩的数据，按照成绩由大到小排名，并输出，应用成员指针*/
using namespace std;

struct student
{
	char name[20];
	int score;
	void print()
	{
		cout <<name<<"的成绩是："<<score<<endl;
	}
};
//排序函数，参数是对一个元素数目为n的结构数组x[]按照student::*p指针指向的数据从大到小排序
void sort(student x[],int n,int student::*p)
{
	//定义函数时，对C++来说一定不要忘记定义形参的类型，因为读取函数时，一般只读取函数的类型，所以有些行参可以不用写。
	for(int m=0;m<n;m++)
		for(int k=m+1;k<n;k++)
			if(x[m].*p<x[k].*p)
				swap(x[m],x[k]);
}

int main()
{
	int i;
	int student::*p = &student::score;
	student s[4]={{"小明",90},{"小红",99},{"小刚",85},{"小华",96}};
	sort(s,4,&student::score);//传递的应该是指针指向数据的地址；
	for(i=0;i<4;i++)
	{
		s[i].print();
	}

	return 0;
}