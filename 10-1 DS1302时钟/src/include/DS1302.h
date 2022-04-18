#ifndef __DS1302_H__
#define __DS1302_H__
void DS302_Init();
void DS1302_WriteByte(unsigned char mycommand, unsigned char mydata) ;
unsigned char DS1302_ReadByte(unsigned char mycommand);
#endif  // !__DS1302_H__
