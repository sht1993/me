#include <iostream>
using namespace std;
#include <string>
/*写一个Coder类，有两个纯虚函数code和decode，写一个Rm类和一个Divx类分别继承
Coder类并实现那两个纯虚函数，写一个File类，有一个setcoder函数
、zip函数和unzip函数。在main函数中使用这个类的对象。*/
class Coder
{ 
public:
	string codername;
public:
	Coder(const char* n):codername(n){};
	virtual void code()=0;
	virtual void decode()=0;
};
class Rm:public Coder
{

public:
	Rm(const char* n):Coder(n){}
	void code()
	{
		cout <<"把"<<codername<<"进行Rm编码"<<endl;
	}
	void decode()
	{
		cout <<"把"<<codername<<"进行Rm解码"<<endl;
	}
};
class Divx:public Coder
{
public:
	Divx(const char* n):Coder(n){}
	void code()
	{
		cout <<"把"<<codername<<"进行Divx编码"<<endl;
	}
	void decode()
	{
		cout <<"把"<<codername<<"进行Divx解码"<<endl;
	}
};
class File
{
	Coder* fc;
	string filename;
public:
	File(const char* n):filename(n)
	{
		fc=NULL;
		cout <<"打开"<<n<<"文件"<<endl;

	}
	void setcoder(Coder& c)
	{
		fc=&c;
	}
	void zip(/*可以放输入输出流*/)
	{
		fc->code();
		cout <<"把"<<fc->codername<<"保存到文件"<<filename<<"中"<<endl;
	}
	void unzip()
	{
		fc->decode();
		cout <<"播放"<<filename<<"中的"<<fc->codername<<endl;
	}
};
int main(int argc, char const *argv[])
{
	File f("D:/dianying");
	Rm r1("<<湄公河惨案>>");
	Divx d1("<<唐伯虎点秋香>>");
	f.setcoder(r1);
	f.zip();
	f.unzip();
	f.setcoder(d1);
	f.zip();
	f.unzip();
	return 0;
}