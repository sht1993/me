#include <iostream>
using namespace std;

void func1()
{
	cout <<"1-int\n"<<"2-double\n"<<"0-long\n";
	int n;
	cin >>n;
	try
	{
		if(n==1) throw 1;
		if(n==2) throw 2.2;
		if(n==0) return;
		throw string("error");
	}
	catch(long e) {cout <<"---long---"<<e<<endl;}
	catch(double e) {cout<<"---double---"<<e<<endl;}
	cout <<"_______end func1________"<<endl;

}
void func2()
{
	try
	{
		func1();
		cout<<"_________in func2__________"<<endl;
	}
	catch(int e)
	{
		cout <<"----int----"<<e<<endl;
	}
	cout <<"_______end func2__________"<<endl;
}
void f3(){cout <<"fashengyichang"<<endl;}
void f1(int n)throw(int,double)
{
	
		if(n==1)throw 1;
		if(n==2)throw 4.5;
		throw "out of range";
	
	
}
int main(int argc, char const *argv[])
{
	set_unexpected(f3);
	try
	{
		// func2();
		int n;
		cin>>n;
		f1(n);
	}
	catch(int e)
	{
		cout<<"---int---"<<e<<endl;
	}
	catch(double e)
	{
		cout<<"---double---"<<e<<endl;
	}
	//catch(...){cout <<"fashengyichang"<<endl;}
	
}