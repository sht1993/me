#include <iostream>
using namespace std;
//体会强制类型转换。四种。
int main()
{
	int a=static_cast<int>(123.45);
	int b=100;
	void* p=&b;
	int* q=static_cast<int*>(p);
	cout <<"b="<<b<< endl ;

	char* r=reinterpret_cast<char*>(q);
	cout<<"r="<<*r<<endl;
	const int c=b;
	cout<<"C="<<c<<endl;
	*const_cast<int*>(&C)=200;
	cout<<"c="<<c<<endl;
	return 0;
}