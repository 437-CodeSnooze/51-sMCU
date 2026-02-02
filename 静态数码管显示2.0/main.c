#include <REGX52.H>
void Delay200us()		//@12.000MHz
{
	unsigned char i, j;

	i = 3;
	j = 82;
	do
	{
		while (--j);
	} while (--i);
}





void lighting(int x,int y)
{
   switch(x)
	{
	case 1:P2_2=0;P2_3=0;P2_4=0;break;
	case 2:P2_2=1;P2_3=0;P2_4=0;break;
	case 3:P2_2=0;P2_3=1;P2_4=0;break;
	case 4:P2_2=1;P2_3=1;P2_4=0;break;
	case 5:P2_2=0;P2_3=0;P2_4=1;break;
	case 6:P2_2=1;P2_3=0;P2_4=1;break;
	case 7:P2_2=0;P2_3=1;P2_4=1;break;
	case 8:P2_2=1;P2_3=1;P2_4=1;break;
	 }
	 switch(y)
	 {
		 case 1:P0=0x30;break;
		 case 2:P0=0x5B;break;
		 case 3:P0=0x4F;break;
		 case 4:P0=0x66;break;
		 case 5:P0=0x6D;break;
		 case 6:P0=0x7D;break;
		 case 7:P0=0x07;break;
		 case 8:P0=0x7F;break;
		 case 9:P0=0x1F;break;
		 case 0:P0=0x3F;break;
	 }
	 Delay200us();
}
void main()
{
	while(1)
 {
   lighting(1,1);
	 lighting(2,2);
	 lighting(3,3);
	 lighting(4,4);
	 lighting(5,5);
	 lighting(6,6);
	 lighting(7,7);
	 lighting(8,8);
 }
}
