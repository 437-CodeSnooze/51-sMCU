#include <REGX52.H>
#include <intrins.h>
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

unsigned char Key()
{
	unsigned char Keynum=0;
	if(P3_1==0){delay();while(P3_1==0);delay();Keynum=1;}
	if(P3_0==0){delay();while(P3_0==0);delay();Keynum=2;}
	if(P3_2==0){delay();while(P3_2==0);delay();Keynum=3;}
	if(P3_3==0){delay();while(P3_3==0);delay();Keynum=4;}
   return Keynum;
}