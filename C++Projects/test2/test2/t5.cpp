#include <iostream>
#include <string>
/*��һ�麬��ѧ�������ͳɼ������ݣ����ճɼ��ɴ�С�������������Ӧ�ó�Աָ��*/
using namespace std;

struct student
{
	char name[20];
	int score;
	void print()
	{
		cout <<name<<"�ĳɼ��ǣ�"<<score<<endl;
	}
};
//�������������Ƕ�һ��Ԫ����ĿΪn�Ľṹ����x[]����student::*pָ��ָ������ݴӴ�С����
void sort(student x[],int n,int student::*p)
{
	//���庯��ʱ����C++��˵һ����Ҫ���Ƕ����βε����ͣ���Ϊ��ȡ����ʱ��һ��ֻ��ȡ���������ͣ�������Щ�вο��Բ���д��
	for(int m=0;m<n;m++)
		for(int k=m+1;k<n;k++)
			if(x[m].*p<x[k].*p)
				swap(x[m],x[k]);
}

int main()
{
	int i;
	int student::*p = &student::score;
	student s[4]={{"С��",90},{"С��",99},{"С��",85},{"С��",96}};
	sort(s,4,&student::score);//���ݵ�Ӧ����ָ��ָ�����ݵĵ�ַ��
	for(i=0;i<4;i++)
	{
		s[i].print();
	}

	return 0;
}