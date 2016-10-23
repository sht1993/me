#include <iostream>
using namespace std;
/*���ƹ��캯��Ӧ�á�
�����Ը������࣬���ó��ȣ���ʼ�������±������ֵ��
�����С���ı䳤��;�����鶨Ϊ�����ͷ��ǿ���ֱ���ͷ�����*/
typedef int T;
class A
{//�����࣬��װ����ǿ����Ĺ���
	T *a;//a�Ƕ������鶯̬�ڴ�ռ��ָ�롣
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
		for(int i=0;i<len;i++) cout <<a[i]<<" ";
		cout <<len<<endl;
	} 
	void fill(const T &start,const T step=T())
	{
		for(int y=0;y<len;y++)
			{
				a[y]=start+step*y;
				// start=start+step;
			}
	}
	A(const A &r)//���������������ã�������ֵݹ�,r��x�����ã�
	{
		len=r.len;//�ȰѶ���ĳ��ȴ��¶���,ֻ�������뿪���¿ռ䡣
		a=new T[len];//�¶�����ݵõ��ĳ��ȣ�Ϊ�¶���a����һ���µĶ�̬�ڴ档
		for(int i=0;i<len;i++)
			a[i]=r.a[i];//�����������Ԫ�ؿ������¿��ٵ��ڴ��r���������Լ��ĳ�Ա�������ó�Ա�������
		cout <<"this array:"<<a<<"copy"<<r.a<<endl;
	}
};
/*���˵������е�ż�����ʾ�����ԭ����*/
A filter(A arr)//����һ�����󣬶�������;��Ƕ�����ࡣ
{//�����β��Ƕ���arr��ʵ����x���½�����arr��Ҫ���ø��ƹ��캯��A(const A &r)�����β��Ƕ���x(A���͵ľɶ���)�ĳ����á�ָ��ͬһ���ڴ档
	for(int i=0;i<arr.size();i++)
	{//��ʾ�����е�ż��
		if(arr.at(i)%2==0)//����ĳ�Ա�����ǵ��ã��ó�Ա�����,������ó�Ա���ݣ�Ҫ�ó�Ա����
			cout <<arr.at(i)<<"  ";
	}
	cout <<endl;
	return arr;
}
int main()
{
	A x(20);
	x.fill(10,3);
	x.show();
	filter(x).show();
	return 0;
}