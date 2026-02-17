#ifndef _MatrixLED_H__
#define _MatrixLED_H__

void _74HC595_WriteByte(unsigned char byte);
void MartrixLED_ShowColumn(unsigned char col,unsigned char Data);
void MatrixLED_Init();


#endif