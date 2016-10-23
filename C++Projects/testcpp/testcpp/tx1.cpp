//#include"stdafx.h"
#include"stdio.h"
void showbits(int var)
{
	typedef unsigned char uc;
	uc* p = (uc*)&var;
	uc byte;
	int j;
	for(j=0;j<4;j++)
	{
		byte=*p;
		int i;
		for(i=0;i<8;i++)
		{
			if(0x80 & byte) putchar('1');
			else putchar('0');//printf("%c","0")
			//putchar(0x80 & byte?'1':'0');
			byte <<= 1;//byte=byte<<1;

		}
		putchar('  ');
		p++;
	}
	puts("");//printf('\n'),»»ÐÐ
}


int main()
{
	int v1=0x61626364;
	showbits(v1);
	return 0;

}