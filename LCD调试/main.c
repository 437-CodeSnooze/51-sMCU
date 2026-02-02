#include <REGX52.H>//
#include"LCD1602.h"

void main ()
{
	LCD_Init();
  LCD_ShowString(1,1,"Hello world");
	LCD_ShowNum(2,1,9527,5);
	while(1);//不加会炸 在显示的时候都要加
}
