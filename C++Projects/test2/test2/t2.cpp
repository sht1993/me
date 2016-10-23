#include <iostream>
#include <string>
using namespace std;
namespace sht
{
	struct student
	{
		char name[20];
		int age;
		void show()
		{
			//cout <<age<<"suida"<<name<<"mengmengda"<<endl;
			cout <<name<<"·ê¿¼±Ø¹ý£¡£¡£¡"<<endl;
		}
};
}
int main()
{
	int i;
	//sht::student s1={"huatong",18};
	using namespace sht;
	student s2;
	strcpy(s2.name,"ÃÈÃÈ");
	s2.age=18;
	for(i=0;i<8;i++)
	{
		//s1.show();
		s2.show();
	};
	return 0;
}