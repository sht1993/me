#include <iostream>
 using namespace std;

 int main()
 {
 	int a[5]={0,1,2,3,4};
 	//int *p=&a[0];
	int *p=a;//数组指针
 	cout <<a[2]<<" "<<p[2]<<endl;//2
 	cout <<1[a]<<" "<<1[p]<<endl;//1
 	cout <<*(a+2)<<" "<<*(p+2)<<endl;//2
 	cout <<&a<<" "<<&a[0]<<" "<<p<<" "<<*p<<endl;//a的首地址,
 	return 0;
 }