#include <REGX52.H>
#include<intrins.h>

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
	 P2=0xFF;
   while(1)
	 {
		 Delay20ms();
	   if(P3_1==0)
		 {
		   Delay20ms();
			 while(P3_1==0);
			 if(P2==0)
				 P2=0xFF;
			 else
			   P2=P2-1;
		 }
	 }

}
