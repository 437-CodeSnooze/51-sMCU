#include <REGX52.H>
#include "Nixie.h"
unsigned char ms;
unsigned char s;
unsigned char min;
unsigned char count;
unsigned char count1;
unsigned char Key1,Key2;
unsigned char countkey;
unsigned char Keyread;

unsigned char Keynum()
{
	unsigned char Keynum=0;
	if(P3_1==0){Keynum=1;}
	if(P3_0==0){Keynum=2;}
	if(P3_2==0){Keynum=3;}
	if(P3_3==0){Keynum=4;}
   return Keynum;
}

void Timer0Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	EA=1;
	PT0=1;
	ET0=1;
}
void Timer1Init(void)		//100微秒@11.0592MHz
{
  TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	EA=1;
	PT1=0;
	ET1=1;
}


void Timer1_calculate() interrupt 3
{
	TF1 = 0;
	TL1 = 0xA4;		
	TH1 = 0xFF;		
  if(count1==10)
	{
				ms++;
			 count1=0;
			if(ms==1000)
			{
				s++;
				ms=0;
			}
			if(s==60)
			{
				min++;
				s=0;
			}
			if(min==100)
			{
				min=0;
			}
	}
	else 
		count1++;
}


void Nixie_Loop() interrupt 1
{
	TF0=0;
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	if(countkey==20)
	{
		countkey=0;
		Key1=Key2;
		Key2=Keynum();
		if(Key1==1&&Key2==0)
			Keyread=1;
		else if(Key1==2&&Key2==0)
			Keyread=2;
		else if(Key1==3&&Key2==0)
			Keyread=3;
		else if(Key1==4&&Key2==0)
			Keyread=4;
	}
	else
		countkey++;
	
	if(count==20)//定2ms
	{
		 Nixie(1,min/10);
		 count++;
	}
	else if(count==40)//定2ms
	{
		 Nixie(2,min%10);
		count++;
	}
	else if(count==60)//定2ms
	{
		 Nixie_a(3);
		count++;
	}
		else if(count==80)//定2ms
	{
		 Nixie(4,s/10);
		count++;
	}
		else if(count==100)//定2ms
	{
		 Nixie(5,s%10);
		count++;
	}
		else if(count==120)//定2ms
	{
		 Nixie_a(6);
		count++;
	}
		else if(count==140)//定2ms
	{
		 Nixie(7,ms%100-(ms/10)%10);
		count++;
	}
		else if(count==160)//定2ms
	{
		 Nixie(8,(ms/10)%10);
		 count=1;
	}
	else
		count++;
}


void allInit()
{
	countkey=1;
	count=1;
	count1=0;
	Timer0Init();
	Timer1Init();
	ms=0;
	s=0;
	min=0;
	Key1=0;
	Key2=0;
	Keyread=0;
}


void main()
{
	allInit();
	while(1)
	{
     		
	}
}
