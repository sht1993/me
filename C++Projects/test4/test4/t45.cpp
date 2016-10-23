#include <iostream>
using namespace std;
/*复制构造函数应用。
构建以个数组类，设置长度，初始化，按下标输出或赋值，
输出大小，改变长度;把数组定为对象，释放是可以直接释放数组*/
typedef int T;
class A
{//数组类，封装和增强数组的功能
	T *a;//a是定义数组动态内存空间的指针。
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
		for(int i=0;i<len;i++) cout <<a[i]<<" ";
		cout <<len<<endl;
	} 
	void fill(const T &start,const T step=T())
	{
		for(int y=0;y<len;y++)
			{
				a[y]=start+step*y;
				// start=start+step;
			}
	}
	A(const A &r)//这里必须是类的引用，以免出现递归,r是x的引用，
	{
		len=r.len;//先把对象的长度传新对象,只针对象必须开辟新空间。
		a=new T[len];//新对象根据得到的长度，为新对象a开辟一块新的动态内存。
		for(int i=0;i<len;i++)
			a[i]=r.a[i];//把引用数组的元素拷贝到新开辟的内存里。r对象引用自己的成员，必须用成员运算符。
		cout <<"this array:"<<a<<"copy"<<r.a<<endl;
	}
};
/*过滤掉数组中的偶数项，显示，输出原数组*/
A filter(A arr)//返回一个对象，对象的类型就是对象的类。
{//函数形参是对象arr，实参是x，新建对象arr需要调用复制构造函数A(const A &r)，其形参是对象x(A类型的旧对象)的常引用。指向同一块内存。
	for(int i=0;i<arr.size();i++)
	{//显示数组中的偶数
		if(arr.at(i)%2==0)//对象的成员必须是调用，用成员运算符,类外调用成员数据，要用成员函数
			cout <<arr.at(i)<<"  ";
	}
	cout <<endl;
	return arr;
}
int main()
{
	A x(20);
	x.fill(10,3);
	x.show();
	filter(x).show();
	return 0;
}