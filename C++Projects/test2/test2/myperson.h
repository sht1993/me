#ifndef _MY_PERSON_H
#define _MY_PERSON_H
#include <iostream>
#include <string>
using namespace std;
extern int thisyear;
/*����һ��ȫ�ֱ���������static��const��extern����ȫ�ֱ���
�������ڶ��ļ�����У�����ȫ�ֱ�����һ��Ҫ��.hͷ�ļ���������
֮����.cpp�ļ��ж��壬����ʹ�ã�����һ����ں����ķ�������֮ǰ
�����ļ���̣�Ϊ�ﵽ��Ϣ���Σ�һ������װΪ.hͷ�ļ���
�䷽��һ�����.cpp�У�������ֻ����ִ�У����ö�����ú����Ľӿ�
�����������ݣ����ڲ�������ķ�װ�ɺں�*/
class Person
{
		string name;
		int year;
		bool sex;
		Person *lover;//�Ѱ��˿��Զ���Ϊָ��
	public:
		Person(const string &n, bool s);//���幹�캯����������ʼ�����������
		void show();
		void love(Person &p1);
};
#endif