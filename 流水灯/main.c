#include <REGX52.H>


void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = ms; i > 0; i--)
        for(j = 110; j > 0; j--);
}

void main()
{
	while(1)
	{
		    delay_ms(150);
			  P2=0x7F;
				delay_ms(150);
				P2=0xBF;
				delay_ms(150);
				P2=0xDF;
				delay_ms(150);
				P2=0xEF;
				delay_ms(150);
				P2=0xF7;
				delay_ms(150);
				P2=0xFB;
				delay_ms(150);
				P2=0xFD;
				delay_ms(150);
				P2=0xFE;
		
	}
}