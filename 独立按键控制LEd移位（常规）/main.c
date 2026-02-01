#include<intrins.h>
#include <REGX52.H>


void Delay20ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 1;
	j = 234;
	k = 113;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	 unsigned char a;
	 P2=0xFE;
   while(1)
	 {
		 Delay20ms();
	   if(P3_1==0)
		 {
		   Delay20ms();
			 if(P3_1==0)
			 {
				 while(P3_1==0);
			   a=2*(~P2);
				 if(a==0)
					 a=0x01;
			   P2=~a;
			 }
		 }
	 }

}

