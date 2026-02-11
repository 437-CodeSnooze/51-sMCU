#include <REGX52.H>


sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}

void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
	I2C_SCL=0;
}

void I2C_Writebyte(unsigned char byte)
{
	unsigned char i;
	I2C_SCL=0;
	
	for(i=0;i<8;i++)
	{
		I2C_SDA=byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}

unsigned char I2C_Readbyte()
{
	unsigned char i;
	unsigned char byte=0x00;
	I2C_SDA = 1;//必要的释放总线
	I2C_SCL=0;
	for(i=0;i<8;i++)
	{
		byte=byte<<1;
		I2C_SCL=1;
		byte=byte|I2C_SDA;
		I2C_SCL=0;
	}
	return byte;
}

void I2C_SendACK(unsigned char sendACK)
{
	I2C_SCL=0;
  I2C_SDA=sendACK;
	I2C_SCL=1;
	I2C_SCL=0;
}

unsigned char I2C_ReadACK()
{ 
	unsigned char ACK;
	I2C_SCL=0;
	ACK=I2C_SDA;
	I2C_SCL=1;
	I2C_SCL=0;
	return ACK;
}