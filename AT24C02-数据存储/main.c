#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"
#include "AT24C02.h"

void main()
{
	//unsigned char i;
	LCD_Init();
	LCD_ShowString(1,1,"OK");
	//LCD_ShowNum(2,1,i,2);
	AT24C02_WriteByte(0,0xAA);
	P2 = AT24C02_ReadByte(0);
	while(1)
	{
		
	}
}
