#include <iostream>
 using namespace std;

 int main()
 {
 	int a[5]={0,1,2,3,4};
 	//int *p=&a[0];
	int *p=a;//����ָ��
 	cout <<a[2]<<" "<<p[2]<<endl;//2
 	cout <<1[a]<<" "<<1[p]<<endl;//1
 	cout <<*(a+2)<<" "<<*(p+2)<<endl;//2
 	cout <<&a<<" "<<&a[0]<<" "<<p<<" "<<*p<<endl;//a���׵�ַ,
 	return 0;
 }