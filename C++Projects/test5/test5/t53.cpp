#include <iostream>
using namespace std;
/*函数调用运算符（）圆括号函数应用，只能定义为类成员函数*/
class Array
{ 
	int *p;//数组名
	int len;//数组长度（元素个数）
public: 
	//带默认值的构造函数,指定数组长度，还要给数组赋值
	Array(int n=10,int value=int()):p(new int[n]),len(n)
	{
		for(int i=0;i<len;i++) p[i]=value;
	}
	void operator ()(int start,int step)//重载（），用来填充数组
	{
		for(int i=0;i<len;i++)
		{
			p[i]=start+i*step;
		}
	}
	int operator ()()//
	{
		int sum=0;
		for(int i=0;i<len;i++)
		{
			sum+=p[i];
		}
		return sum;
	}
	friend ostream &operator << (ostream &o,Array &a1)//重载<<实现输出数组对象各个元素
	{
		for(int i=0;i<a1.len-1;i++)
		o <<a1.p[i]<<",";
		o <<a1.p[a1.len-1];
		return o;
	}
};
int main()
{
	Array a1;
	a1(5,1);//从5开始按照步长为1,填充；a.operator() (5,1)
	cout <<a1<<endl;
	cout <<a1()<<endl;

	return 0;
}