#ifndef _I2C_H__
#define _I2C_H__
void I2C_Start();
void I2C_Stop();
void I2C_WriteByte(unsigned char byte);
unsigned char I2C_Readbyte();
void I2C_SendACK(unsigned char sendACK);
unsigned char I2C_ReadACK();

#endif