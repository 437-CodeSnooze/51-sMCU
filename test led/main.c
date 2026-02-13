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
        P2 = 0x55;  
        delay_ms(200);  
        P2 = 0xAA;  
        delay_ms(200);  
    }
}
	