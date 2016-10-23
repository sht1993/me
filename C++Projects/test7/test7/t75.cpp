#include <iostream>
#include <cctype>
using namespace std;

istream& func(istream& i)
{
	char c;//一个个的选出非数字字符
	/*
	do
             statement
     while   (condition);
	在求解 condition 之前，先执行了 do 里面的 statement。
	condition 不能为空。如果 condition 的值为假，
	则循环结束，否则循环重复执行。*/
	do
	i>>c;//输入到函数中
	while(!isdigit(c));//判断是否是数字，是返回这个输入的字符，否则继续
	i.putback(c);//已经输入，返回的是当下前面的一个字符。（退回一个字符）
	return i;//i就是cin
}
// #include <windows.h>
int main(int argc, char const *argv[])
{
	// int n=-1;
	// cin>>func>>n;
	// cout <<"n="<<n<<endl;
	char a,b,c,d,e;
	a=cin.get();
	cin.get(b);
	cin.ignore();
	c=cin.peek();
	cin.get(d);
	cin.putback(d);
	cin.get(e);
	
	cout <<a<<b<<c<<d<<e<<endl;
/*//C中，fflash刷新。
	cerr <<"world";
	cout <<"hello";// 缓冲：输入、换行、内存满，结束、刷新
	
	Sleep(3000); 
	//cout <<endl;*/
	return 0;
}