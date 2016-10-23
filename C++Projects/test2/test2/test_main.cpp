	#include "myperson.h"
/*主函数，生成对象，输出*/
//int thisyear;
int main()
{ 
	thisyear=1993;
	Person per1("许文强",true);
	thisyear=1996;
	Person per2("冯程程",false);
	thisyear=2011;
	cout <<"在"<<thisyear<<"年"<<endl;
	per1.show();
	per2.show();
	thisyear=2018;
	cout<<"转眼过了。。。年。。。,这是"<<thisyear<<"年"<<endl;
	per2.love(per1);
	per1.show();
	per2.show();

	return 0;
}