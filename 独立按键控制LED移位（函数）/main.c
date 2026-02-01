#include <REGX52.H>
#include<intrins.h>
void delay()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 1;
	j = 216;
	k = 35;
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
	P2=0xFE;
	while(1)
 {
   if(P3_1==0)
	 {
		 delay();
     if(P3_1==0)
		 {
		   delay();
			 while(P3_1==0);
			 P2=_crol_(P2,1);
			 
		 }			 
	 }
 }
}