#include <REGX52.H>
#include"Key.h"
#include"MatrixKey.h"
#include"Nixie.h"
#include"Delay.h"

unsigned char ReadKey;
unsigned char count ; 

void main()
{
		count=0;
	  Nixie(1,count);//必要初始化
	  while(1)
		{
			  ReadKey=Key();
			if(ReadKey)
			{
			  if(ReadKey==1)
			  {
					count++;
				  if(count==10)
				   {
					  count=0;
				   }
			   }
			  else if(ReadKey==2)
			  {
				   if(count==0)
				   {
					  count=10;
				   }
				    count--;
			   }
        Nixie(1,count);
				ReadKey=0;
			}
		}			
}
