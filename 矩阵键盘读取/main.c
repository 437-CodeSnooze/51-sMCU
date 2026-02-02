#include <REGX52.H>
#include <intrins.h>
#include"LCD1602.h"
#include"MatrixKey.h"
unsigned char i;
void main()
{
	 LCD_Init();
	 LCD_ShowString(1,1,"Hello world");
	 
   while(1)
	 {
	    i=MatrixKey();
		 if(i)
		 {
		   LCD_ShowNum(2,1,i,3);
		 }
	 }
}
