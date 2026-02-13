#include <REGX52.H>
#include <intrins.h>

void delay1()		//@12.000MHz
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
unsigned char MatrixKey()
{
   unsigned char key=0;
	 P1=0xFF;
	 P1_3=0;
	 if(P1_7==0){delay1();while(P1_7==0);delay1();key=1;}
	 if(P1_6==0){delay1();while(P1_6==0);delay1();key=5;}
	 if(P1_5==0){delay1();while(P1_5==0);delay1();key=9;}
	 if(P1_4==0){delay1();while(P1_4==0);delay1();key=13;}
	 P1=0xFF;
	 P1_2=0;
	 if(P1_7==0){delay1();while(P1_7==0);delay1();key=2;}
	 if(P1_6==0){delay1();while(P1_6==0);delay1();key=6;}
	 if(P1_5==0){delay1();while(P1_5==0);delay1();key=10;}
	 if(P1_4==0){delay1();while(P1_4==0);delay1();key=14;}
	 P1=0xFF;
	 P1_1=0;
	 if(P1_7==0){delay1();while(P1_7==0);delay1();key=3;}
	 if(P1_6==0){delay1();while(P1_6==0);delay1();key=7;}
	 if(P1_5==0){delay1();while(P1_5==0);delay1();key=11;}
	 if(P1_4==0){delay1();while(P1_4==0);delay1();key=15;}
	 P1=0xFF;
	 P1_0=0;
	 if(P1_7==0){delay1();while(P1_7==0);delay1();key=4;}
	 if(P1_6==0){delay1();while(P1_6==0);delay1();key=8;}
	 if(P1_5==0){delay1();while(P1_5==0);delay1();key=12;}
	 if(P1_4==0){delay1();while(P1_4==0);delay1();key=16;}
	
	return key;
}