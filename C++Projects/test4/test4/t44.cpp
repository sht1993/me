#include <iostream>
using namespace std;
/*构建以个数组类，设置长度，初始化，按下标输出或赋值，
输出大小，改变长度;把数组定为对象，释放是可以直接释放数组*/
typedef double T;
class A
{//数组类，封装和增强数组的功能
	T *a;
	int len;
public:
	A(int n, T init=T()/*零初始化*/):len(n),a(new T[n]/*new 类型[n]:开辟一个n元素数组空间,返回一个指针指向数组内数据*/)
	{
		for(int i=0;i<n;i++) a[i]=init;/*指针数组int a[5]={...},int *p=a;a[1]=p[1];*/
		cout <<a<<" creat  "<<len<<" element "<<init<<endl;
	}
	~A(){
		delete[] a;a=NULL;
		cout <<" free "<<a<<endl;
	}
	T &at(int index)//按下标输出数组中的元素，把引用函数，引用动态存储空间里的数据
	{
		if(index<0||index>>len) throw "输入下标异常";//越界抛出异常，结束程序。
		return a[index];//返回指定下标的数组元素，并且返回类型是T
	}
	int size(){return len;}
	void resize(int newsize,const T &val=T())
	{//重新设置数组长度，并且再加长的条件下，传递新的元素值
		if(newsize<len) len=newsize;//缩短不用改变。
		else 
		{
			T *new_a=new T[newsize];//不够用，先开辟一块元素个数为newsize的T类型的数组动态存储空间，返回指向该数组数据的指针
			for(int i=0;i<len;i++)
			{
				new_a[i]=a[i];//先把原来的数组从原来的动态存储空间里复制到新的动态空间。
			}
			for(int j=len;j<newsize;j++)
			{
				new_a[j]=val;//把向数组内新添加的数据赋值到动态存储空间。
			}
			delete [] a;//释放就空间
			a=new_a;//把a指向新空间，
			len=newsize;//记录新数组的元素个数。
		}
	}
	void show()
	{
		for(int k=0;k<len;k++) cout <<a[k]<<"  ";
		cout <<len<<endl;
	}

};
int main()
{
	A x(20);
	x.show();
	x.at(4)=10;
	// x.at(25)=10;//throw.
	x.size();
	x.resize(25,1);
	x.show();
	return 0;
}