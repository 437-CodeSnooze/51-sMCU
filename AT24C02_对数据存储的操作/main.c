#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"
#include "AT24C02.h"
#include "MatrixKey.h"
void main()
{
	unsigned char count=1;
	unsigned char keyread=0;
	LCD_Init();
	LCD_ShowString(1,1,"count");
	while(1)
	{
		//keyread=MatrixKey();
		keyread=Key();
		switch(keyread)
		{
			case 1:count++;break;
			case 2:count--;break;
			case 3:AT24C02_WriteByte(0,count);Delay(5);break;
			case 4:count=AT24C02_ReadByte(0);break;
		}
		Delay(5);
		LCD_ShowNum(2,1,count,2);
	}
}
