	#include "myperson.h"
/*�����������ɶ������*/
//int thisyear;
int main()
{ 
	thisyear=1993;
	Person per1("����ǿ",true);
	thisyear=1996;
	Person per2("��̳�",false);
	thisyear=2011;
	cout <<"��"<<thisyear<<"��"<<endl;
	per1.show();
	per2.show();
	thisyear=2018;
	cout<<"ת�۹��ˡ������ꡣ����,����"<<thisyear<<"��"<<endl;
	per2.love(per1);
	per1.show();
	per2.show();

	return 0;
}