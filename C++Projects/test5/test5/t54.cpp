#include <iostream>
using namespace std;
/*指针运算符，成员访问运算符使用*/
struct Point
{
	int x;
	int y;
};
class Pos
{
	Point p;
	public:
		Pos(int x=0,int y=0)
		{
			p.x=x;
			p.y=y;
		}
		Pos move(int a,int b)
		{
			return Pos(p.x+=a,p.y+=b);
		}
		void show()
		{
			cout<<p.x<<"  "<<p.y<<endl；
		}
		Point *operator ->(){return &p;}//转向P的地址。
		friend ostream &operator <<(ostream &o,const Pos &p);
};
ostream &operator <<(ostream &o,const Pos &a)
{
	o<<"("<<a.p.x<<","<<a.p.y<<")"<<endl;//这里有两层，注意对象.结构体成员变量.结构体数据
	return o;
}
int main()
{
	Pos p(20,30);
	cout <<p;
	cout <<p->x<<" "<<p->y<<endl;
	p.show();
	p.move(10,30);
	cout <<p;
	return 0;
}