#include <iostream>
#include <string>
using namespace std;

class Buffer{
	string name;
public:
	Buffer(const string &filename):name(filename)
	{
		cout <<"create"<<filename<<"buffer"<<endl;
	}
	~Buffer()
	{
		cout <<"clean"<<name<<"buffer"<<endl;
	}
};
class File{
	string path;
	Buffer *p;
public:
	
	File(const string &name="not name"):path(name),p(0)
	{
		cout <<this<<"create a new File"<<path<<endl;
	}//分清实参和形参。构造函数初始化列表，并且默认参数值。
	~File(){
		//析构函数，用来释放对象，在对象生命周期结束时。
		cout <<this<<path<<"free space"<<endl;
		close();//析构时用来释放动态缓冲区
	}
	void open()
	{
		p=new Buffer(path);//create 动态缓冲区

	}
	void close()
	{
		delete p;p=NULL;
	}
};

int main()
{
	/*File *p1= new File;
	File *p2= new File("passwd");
	File *p3= new File("passwd1");
	File *p4= new File("passwd2");
	File *p5= new File[3];
	delete p1;p1=NULL;//new建立的对象，何时delete，在delete之前析构，
	delete p2;p2=NULL;
	delete p3;p2=NULL;
	delete p4;p2=NULL;
	delete[] p5;p5=NULL;//表示释放一组，释放之前析构，先构造的后析构，后构造的先析构。
*/	
	//File a("bbb")
	File *p2= new File("passwd");
	p2->open();
	delete p2;p2=NULL;
	return 0;
}