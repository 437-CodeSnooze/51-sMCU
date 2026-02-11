#include <REGX52.H>
#include "I2C.h"

void AT24C02_WriteByte(unsigned char Waddress,unsigned char byte)
{
	I2C_Start();
	I2C_WriteByte(0xA0);
	I2C_ReadACK();
	I2C_WriteByte(Waddress);
	I2C_ReadACK();
	I2C_WriteByte(byte);
	I2C_ReadACK();
	I2C_Stop();
}

unsigned char AT24C02_ReadByte(unsigned char Waddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_WriteByte(0xA0);
	I2C_ReadACK();
	I2C_WriteByte(Waddress);
	I2C_ReadACK();
	I2C_Start();
	I2C_WriteByte(0xA1);
	I2C_ReadACK();
	Data=I2C_Readbyte();
	I2C_SendACK(1);
	I2C_Stop();
	return Data;
}