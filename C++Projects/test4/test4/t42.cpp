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
	}//����ʵ�κ��βΡ����캯����ʼ���б�����Ĭ�ϲ���ֵ��
	~File(){
		//���������������ͷŶ����ڶ����������ڽ���ʱ��
		cout <<this<<path<<"free space"<<endl;
		close();//����ʱ�����ͷŶ�̬������
	}
	void open()
	{
		p=new Buffer(path);//create ��̬������

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
	delete p1;p1=NULL;//new�����Ķ��󣬺�ʱdelete����delete֮ǰ������
	delete p2;p2=NULL;
	delete p3;p2=NULL;
	delete p4;p2=NULL;
	delete[] p5;p5=NULL;//��ʾ�ͷ�һ�飬�ͷ�֮ǰ�������ȹ���ĺ��������������������
*/	
	//File a("bbb")
	File *p2= new File("passwd");
	p2->open();
	delete p2;p2=NULL;
	return 0;
}