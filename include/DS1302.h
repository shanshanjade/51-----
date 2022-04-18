#ifndef __DS1302_H__
#define __DS1302_H__
void DS302_Init();
void DS1302_WriteByte(unsigned char command, unsigned char data);
unsigned char DS1302_ReadByte(unsigned char command);
#endif  // !__DS1302_H__
