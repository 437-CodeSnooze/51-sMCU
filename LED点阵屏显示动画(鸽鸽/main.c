#include <REGX52.H>
#include "Delay.h"
#include "Matrix LED.h"
unsigned char i;
unsigned char a = 0;


sbit RCK=P3^5;     //RCLK
sbit SCK=P3^6;     //SRCLK
sbit SER=P3^4;     //SER

unsigned char Animation[48] = 
{
0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
0x00,0x00,0x01,0x02,0x1C,0x1C,0x7B,0x58,
0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
0x00,0x00,0x23,0x7C,0xF8,0xB6,0x01,0x00,
0x00,0x00,0x01,0x02,0x24,0x78,0xFF,0xB0,
0x00,0x00,0x23,0x7C,0xF8,0xB6,0x01,0x00
};


void main()
{
  MatrixLED_Init();
	while(1)
	{
      for(i=0;i<48;)
		{
			
      i=i+8;
			MartrixLED_ShowColumn(0,Animation[i]);
			MartrixLED_ShowColumn(1,Animation[i+1]);
			MartrixLED_ShowColumn(2,Animation[i+2]);
			MartrixLED_ShowColumn(3,Animation[i+3]);
			MartrixLED_ShowColumn(4,Animation[i+4]);
			MartrixLED_ShowColumn(5,Animation[i+5]);
			MartrixLED_ShowColumn(6,Animation[i+6]);
			MartrixLED_ShowColumn(7,Animation[i+7]);
			if(i==40)
			{
				i=0;
			}
			Delay(100);
		}
	}
}
