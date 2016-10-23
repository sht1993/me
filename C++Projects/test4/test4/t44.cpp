#include <iostream>
using namespace std;
/*�����Ը������࣬���ó��ȣ���ʼ�������±������ֵ��
�����С���ı䳤��;�����鶨Ϊ�����ͷ��ǿ���ֱ���ͷ�����*/
typedef double T;
class A
{//�����࣬��װ����ǿ����Ĺ���
	T *a;
	int len;
public:
	A(int n, T init=T()/*���ʼ��*/):len(n),a(new T[n]/*new ����[n]:����һ��nԪ������ռ�,����һ��ָ��ָ������������*/)
	{
		for(int i=0;i<n;i++) a[i]=init;/*ָ������int a[5]={...},int *p=a;a[1]=p[1];*/
		cout <<a<<" creat  "<<len<<" element "<<init<<endl;
	}
	~A(){
		delete[] a;a=NULL;
		cout <<" free "<<a<<endl;
	}
	T &at(int index)//���±���������е�Ԫ�أ������ú��������ö�̬�洢�ռ��������
	{
		if(index<0||index>>len) throw "�����±��쳣";//Խ���׳��쳣����������
		return a[index];//����ָ���±������Ԫ�أ����ҷ���������T
	}
	int size(){return len;}
	void resize(int newsize,const T &val=T())
	{//�����������鳤�ȣ������ټӳ��������£������µ�Ԫ��ֵ
		if(newsize<len) len=newsize;//���̲��øı䡣
		else 
		{
			T *new_a=new T[newsize];//�����ã��ȿ���һ��Ԫ�ظ���Ϊnewsize��T���͵����鶯̬�洢�ռ䣬����ָ����������ݵ�ָ��
			for(int i=0;i<len;i++)
			{
				new_a[i]=a[i];//�Ȱ�ԭ���������ԭ���Ķ�̬�洢�ռ��︴�Ƶ��µĶ�̬�ռ䡣
			}
			for(int j=len;j<newsize;j++)
			{
				new_a[j]=val;//��������������ӵ����ݸ�ֵ����̬�洢�ռ䡣
			}
			delete [] a;//�ͷžͿռ�
			a=new_a;//��aָ���¿ռ䣬
			len=newsize;//��¼�������Ԫ�ظ�����
		}
	}
	void show()
	{
		for(int k=0;k<len;k++) cout <<a[k]<<"  ";
		cout <<len<<endl;
	}

};
int main()
{
	A x(20);
	x.show();
	x.at(4)=10;
	// x.at(25)=10;//throw.
	x.size();
	x.resize(25,1);
	x.show();
	return 0;
}