#include <iostream>
#include <string>
#include "myperson.h"//�������ͷ�ļ�
/*��ĳ�Ա������Ҳ�Ʒ���*/
using namespace std;
int thisyear;//����һ��ȫ�ֱ�������С��Χ�ھֲ��������ȡ�
Person::Person(const string &n, bool s)//���幹�캯����������ʼ�����������
	{
		/*nֻ������ʵ��������ݣ�û��Ҫ����һ�ݣ�
		Ҳû��Ҫ�Ķ�,���������ã��Ҷ���Ϊ������������βκ͸�ֵ��������
		������������עperson::name=name*/
		name=n;
		year=thisyear;
		sex=s;
		lover = NULL;
	}
void Person::show()
	{
		cout <<"���ǣ�"<<name<<",������"<<thisyear-year<<"��,"<<(sex?"�Ϻ�̲������":"ҹ�Ϻ�һ֦��")<<",";
		if (lover)
			cout <<"����Ⱥ�п���"<<lover->name<<"һ�۾Ͱ�������"<<endl;
		else
			cout <<"����"<<endl;

	}
void Person::love(Person &p1)//������β�per1�Ƿ���Բ�д��������ֱ������ʵ��
{
	//thisָ����øó�Ա�����Ķ������е�ǰ������׵�ַ���ݸ�this
	lover=&p1;//�ȼ���per2.lover=&p1=(*this).lover=&p1;per2=*this;
	p1.lover=this;//��per2��ַ��Ҳ����this�����ݸ�ʵ�ε�loverָ�룻
}