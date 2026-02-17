#include <REGX52.H>
#include "Delay.h"
sbit RCK=P3^5;     //RCLK
sbit SCK=P3^6;     //SRCLK
sbit SER=P3^4;     //SER

void _74HC595_WriteByte(unsigned char byte)
{
	unsigned char i=0;
	for (i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);
		SCK=0;
		SCK=1;
	}
	RCK=0;
	RCK=1;
}

void MatrixLED_ShowColumn(unsigned char col,unsigned char Data)
{
	_74HC595_WriteByte(Data);
	P0=~(0x80>>col);
	Delay(1);
	P0=0xFF;
}



void MatrixLED_Init()
{
		SCK=1;
	  RCK=1;
}
