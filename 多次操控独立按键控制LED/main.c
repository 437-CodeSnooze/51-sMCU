#include <REGX52.H>
#include "Key.h"
#include "Delay.h"
unsigned char count;
unsigned char keynum;

void Init_T0()
{
	TMOD|=0x06;
	TH0=0xFD;
	TL0=0xFD;
	EA=1;
	ET0=1;
	TR0=1;
}

void Isr_T0()  interrupt 1
{
	P2=~P2;
}

void main()
{
	P2=0xFF;
	INit_T0();
	while(1)
	{
		 keynum=Key();
		if(keynum!=0)
		{
			P3_4=1;
			P3_4=0;
		}
	}
}