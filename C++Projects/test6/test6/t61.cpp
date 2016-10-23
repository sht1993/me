#include <iostream>
using namespace std;
#include <string>
/*дһ��Coder�࣬���������麯��code��decode��дһ��Rm���һ��Divx��ֱ�̳�
Coder�ಢʵ�����������麯����дһ��File�࣬��һ��setcoder����
��zip������unzip��������main������ʹ�������Ķ���*/
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
		cout <<"��"<<codername<<"����Rm����"<<endl;
	}
	void decode()
	{
		cout <<"��"<<codername<<"����Rm����"<<endl;
	}
};
class Divx:public Coder
{
public:
	Divx(const char* n):Coder(n){}
	void code()
	{
		cout <<"��"<<codername<<"����Divx����"<<endl;
	}
	void decode()
	{
		cout <<"��"<<codername<<"����Divx����"<<endl;
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
		cout <<"��"<<n<<"�ļ�"<<endl;

	}
	void setcoder(Coder& c)
	{
		fc=&c;
	}
	void zip(/*���Է����������*/)
	{
		fc->code();
		cout <<"��"<<fc->codername<<"���浽�ļ�"<<filename<<"��"<<endl;
	}
	void unzip()
	{
		fc->decode();
		cout <<"����"<<filename<<"�е�"<<fc->codername<<endl;
	}
};
int main(int argc, char const *argv[])
{
	File f("D:/dianying");
	Rm r1("<<�ع��ӲҰ�>>");
	Divx d1("<<�Ʋ���������>>");
	f.setcoder(r1);
	f.zip();
	f.unzip();
	f.setcoder(d1);
	f.zip();
	f.unzip();
	return 0;
}