#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	if(argc!=3)
	{
		cout <<*argv<<"-c|-d�ļ���"<<endl;
		return 0;
	}
	fstream f(argv[2],ios::in|ios::out);
	if(!f)
	{
		cout<<"open file fulse"<<endl;
		return 1;
	}
	char c;
	if(strcmp(argv[1],"-c")==0)
	{
		while(f.get(c))
		{
			f.seekp(-1,ios::cur);
			f.put(~c+66);
		}
	}
	else if(strcmp(argv[1],"-d")==0)
	{
		while(f.get(c))
		{
			f.seekp(-1,ios::cur);
			f.put(~(c-66));
		}
	}
	else
	{
		cout <<"��Чѡ�ֻ����-c����-d"<<endl;
	}
	f.close();
	return 0;
}